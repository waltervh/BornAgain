// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/GroupItem.h
//! @brief     Defines class GroupItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef GROUPITEM_H
#define GROUPITEM_H

#include "SessionItem.h"
#include "GroupInfo.h"
#include <memory>

class GroupInfo;
class GroupItemController;

class BA_CORE_API_ GroupItem : public SessionItem
{
public:
    static const QString T_ITEMS;
    GroupItem();
    ~GroupItem();

    void setGroupInfo(const GroupInfo& groupInfo);
    SessionItem* currentItem() const;

    QString currentType() const;

    SessionItem* setCurrentType(const QString& modelType);

    QStringList translateList(const QStringList& list) const;

    SessionItem* getItemOfType(const QString& type);

private:
    void onValueChange();
    void updateComboValue();
    std::unique_ptr<GroupItemController> m_controller;
};

#endif // GROUPITEM_H

