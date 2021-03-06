// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/InfoWidgets/DistributionEditor.h
//! @brief     Defines class DistributionEditor
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef DISTRIBUTIONEDITOR_H
#define DISTRIBUTIONEDITOR_H

#include "SessionItemWidget.h"

class QGroupBox;
class GroupItem;
class DistributionWidget;
class ComponentFlatView;
class DistributionItem;

//! The DistributionEditor class, being a child of DistributionDialog, contains a widget
//! to show Distribution1D and property editor to change distribution parameters.

class BA_CORE_API_ DistributionEditor : public SessionItemWidget
{
    Q_OBJECT
public:
    DistributionEditor(QWidget* parent = nullptr);

    void setNameOfEditor(QString name);

protected:
    void subscribeToItem();

private:
    void onPropertyChanged(const QString& property_name);
    GroupItem* groupItem();
    DistributionItem* distributionItem();

    ComponentFlatView* m_propertyEditor;
    GroupItem* m_item;
    DistributionWidget* m_plotwidget;
    QString m_nameOfEditor;
    QGroupBox* m_box;
};

#endif // DISTRIBUTIONEDITOR_H
