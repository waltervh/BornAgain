// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Models/ParticleLayoutItem.cpp
//! @brief     Implements class ParticleLayoutItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "ParticleLayoutItem.h"
#include "ParticleCoreShellItem.h"
#include "ParticleDistributionItem.h"
#include "ComboProperty.h"

const QString ParticleLayoutItem::P_APPROX = "Approximation";
const QString ParticleLayoutItem::P_TOTAL_DENSITY = "Total particle density";

ParticleLayoutItem::ParticleLayoutItem(ParameterizedItem *parent)
    : ParameterizedGraphicsItem(Constants::ParticleLayoutType, parent)
{
    ComboProperty approx;
    approx << "Decoupling Approximation" << "Size Space Coupling Approximation";
    registerProperty(P_APPROX, approx.getVariant());
    registerProperty(P_TOTAL_DENSITY, 1.0);

    addToValidChildren(Constants::ParticleType, PortInfo::PORT_0);
    addToValidChildren(Constants::ParticleCoreShellType, PortInfo::PORT_0);
    addToValidChildren(Constants::ParticleCompositionType, PortInfo::PORT_0);
    addToValidChildren(Constants::ParticleDistributionType, PortInfo::PORT_0);
    addToValidChildren(Constants::InterferenceFunctionRadialParaCrystalType, PortInfo::PORT_1, 1);
    addToValidChildren(Constants::InterferenceFunction2DParaCrystalType, PortInfo::PORT_1, 1);
    addToValidChildren(Constants::InterferenceFunction1DLatticeType, PortInfo::PORT_1, 1);
    addToValidChildren(Constants::InterferenceFunction2DLatticeType, PortInfo::PORT_1, 1);
}

ParticleLayoutItem::~ParticleLayoutItem()
{
}

void ParticleLayoutItem::insertChildItem(int row, ParameterizedItem *item)
{
    ParameterizedItem::insertChildItem(row, item);
    if (item->modelType() == Constants::ParticleType
        || item->modelType() == Constants::ParticleCoreShellType
        || item->modelType() == Constants::ParticleCompositionType
        || item->modelType() == Constants::ParticleDistributionType) {
        int port = item->getRegisteredProperty(ParameterizedItem::P_PORT).toInt();
        if (port == PortInfo::DEFAULT) {
            item->setItemPort(PortInfo::PORT_0);
        }
    } else if (item->modelType() == Constants::InterferenceFunctionRadialParaCrystalType
               || item->modelType() == Constants::InterferenceFunction2DParaCrystalType
               || item->modelType() == Constants::InterferenceFunction1DLatticeType
               || item->modelType() == Constants::InterferenceFunction2DLatticeType) {
        int port = item->getRegisteredProperty(ParameterizedItem::P_PORT).toInt();
        if (port == PortInfo::DEFAULT) {
            item->setItemPort(PortInfo::PORT_1);
        }
    }
}

void ParticleLayoutItem::onChildPropertyChange()
{
    for (auto child_item : childItems()) {
        if (child_item->modelType() == Constants::InterferenceFunction2DParaCrystalType
            || child_item->modelType() == Constants::InterferenceFunction2DLatticeType) {
            setPropertyAppearance(P_TOTAL_DENSITY, PropertyAttribute::DISABLED);
            ParameterizedItem::onChildPropertyChange();
            return;
        }
    }
    setPropertyAppearance(P_TOTAL_DENSITY, PropertyAttribute::VISIBLE);
    ParameterizedItem::onChildPropertyChange();
}
