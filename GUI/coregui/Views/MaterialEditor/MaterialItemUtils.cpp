// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/MaterialEditor/MaterialItemUtils.cpp
//! @brief     Implements class MaterialItemUtils
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "MaterialItemUtils.h"
#include "AppSvc.h"
#include "ComboProperty.h"
#include "DesignerHelper.h"
#include "GUIHelpers.h"
#include "LayerItem.h"
#include "Material.h"
#include "MaterialDataItems.h"
#include "MaterialEditorDialog.h"
#include "MaterialItem.h"
#include "MaterialItemContainer.h"
#include "MaterialModel.h"
#include "MesoCrystalItem.h"
#include "ParticleCompositionItem.h"
#include "ParticleCoreShellItem.h"
#include "ParticleDistributionItem.h"
#include "ParticleItem.h"
#include "ParticleLayoutItem.h"
#include <QColorDialog>

namespace
{

std::map<QString, QString> get_tag_map()
{
    std::map<QString, QString> result = {
        {Constants::ParticleCompositionType, ParticleCompositionItem::T_PARTICLES},
        {Constants::ParticleDistributionType, ParticleDistributionItem::T_PARTICLES},
        {Constants::ParticleLayoutType, ParticleLayoutItem::T_PARTICLES},
        {Constants::MesoCrystalType, MesoCrystalItem::T_BASIS_PARTICLE}};
    return result;
}
}

QColor MaterialItemUtils::suggestMaterialColor(const QString &name)
{
    if(name.contains("Air") ) {
        return QColor(179, 242, 255);
    }
    else if(name.contains("Substrate") ) {
        return QColor(205,102,0);
    }
    else if ( name.contains("Default") ) {
        return QColor(Qt::green);
    }
    else if ( name.contains("Particle") ) {
        return QColor(146, 198, 255);
    }
    else {
        return DesignerHelper::getRandomColor();
    }
}


ExternalProperty MaterialItemUtils::defaultMaterialProperty()
{
    if (!AppSvc::materialModel())
        return ExternalProperty();

    auto materials = AppSvc::materialModel()->topItems();
    return materials.isEmpty() ? ExternalProperty() :
                                 MaterialItemUtils::materialProperty(*materials.front());
}


std::unique_ptr<Material>
MaterialItemUtils::createDomainMaterial(const ExternalProperty &material_property)
{
    MaterialItem* materialItem = findMaterial(material_property);
    return materialItem->createMaterial();
}

std::unique_ptr<Material>
MaterialItemUtils::createDomainMaterial(const ExternalProperty& material_property,
                                        const MaterialItemContainer& container)
{
    const MaterialItem* material_item = container.findMaterialById(material_property.identifier());
    if (!material_item)
        throw GUIHelpers::Error("MaterialUtils::createDomainMaterial() -> Error. Can't find "
                                "material with name '"
                                + material_property.text() + "'.");
    return material_item->createMaterial();
}

MaterialItem* MaterialItemUtils::findMaterial(const ExternalProperty& material_property)
{
    if (!AppSvc::materialModel())
        throw GUIHelpers::Error("MaterialItemUtils::findMaterial() -> Error. "
                                "Attempt to access non-existing material model");

    auto material = AppSvc::materialModel()->materialFromIdentifier(material_property.identifier());

    if(!material)
        throw GUIHelpers::Error("MaterialUtils::findMaterial() -> Error. Can't find "
                                "material with name '"+material_property.text()+"'.");
    return material;
}

//! Returns material tag for given item. Returns empty string, if item doesn't have materials.

QString MaterialItemUtils::materialTag(const SessionItem &item)
{
    QString result;
    if (item.modelType() == Constants::ParticleType) {
        result = ParticleItem::P_MATERIAL;
    } else if (item.modelType() == Constants::LayerType) {
        result = LayerItem::P_MATERIAL;
    }
    return result;
}

//! Returns list of model types which contains registered MaterialProperty.

QStringList MaterialItemUtils::materialRelatedModelTypes()
{
    return {Constants::ParticleType, Constants::LayerType};
}

//! Constructs material property for given material.

ExternalProperty MaterialItemUtils::materialProperty(const SessionItem& materialItem)
{
    ExternalProperty result;

    ExternalProperty colorProperty = materialItem.getItemValue(MaterialItem::P_COLOR).value<ExternalProperty>();
    result.setIdentifier(materialItem.getItemValue(MaterialItem::P_IDENTIFIER).toString());
    result.setColor(colorProperty.color());
    result.setText(materialItem.itemName());

    return result;
}

ExternalProperty MaterialItemUtils::colorProperty(const QColor& color)
{
    ExternalProperty result;
    result.setColor(color);
    result.setText(QString("[%1, %2, %3] (%4)")
                   .arg(color.red()).arg(color.green()).arg(color.blue()).arg(color.alpha()));
    return result;
}

ExternalProperty MaterialItemUtils::selectMaterialProperty(const ExternalProperty& previous)
{
    MaterialEditorDialog dialog(AppSvc::materialModel());
    dialog.setMaterialProperty(previous);
    if(dialog.exec() == QDialog::Accepted) {
        return dialog.selectedMaterialProperty();
    }

    return ExternalProperty();
}


ExternalProperty MaterialItemUtils::selectColorProperty(const ExternalProperty& previous)
{
    ExternalProperty result;

#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    auto oldColor = previous.color();
    auto newColor = QColorDialog::getColor(oldColor);
    if (oldColor != newColor)
        result = MaterialItemUtils::colorProperty(newColor);
#else
    bool ok = false;
    QRgb oldRgba = previous.color().rgba();
    QRgb newRgba = QColorDialog::getRgba(oldRgba, &ok, nullptr);
    if (ok && newRgba != oldRgba)
        result = MaterialItemUtils::colorProperty(QColor::fromRgba(newRgba));
#endif

    return result;
}

QVector<SessionItem*> MaterialItemUtils::materialPropertyItems(SessionItem* item)
{
    static const std::map<QString, QString> tag_map = get_tag_map();
    QVector<SessionItem*> materials;
    QList<SessionItem*> particle_holders{item};
    while (!particle_holders.isEmpty()) {
        auto item = particle_holders.takeFirst();
        if (!item)
            continue;

        const QString model_type = item->modelType();
        auto iter = tag_map.find(model_type);
        if (iter != tag_map.end()) {
            particle_holders.append(QList<SessionItem*>::fromVector(item->getItems(iter->second)));
            continue;
        }

        if (model_type == Constants::ParticleType)
            materials.append(static_cast<ParticleItem*>(item)->materialPropertyItems());
        else if (model_type == Constants::ParticleCoreShellType)
            materials.append(static_cast<ParticleCoreShellItem*>(item)->materialPropertyItems());
        else
            throw GUIHelpers::Error(
                "Error in MaterialItemUtils::materialProperties: cannot handle passed model type '"
                + model_type + "'");
    }
    return materials;
}
