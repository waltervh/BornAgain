// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/RealDataModel.h
//! @brief     Defines class RealDataModel
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef REALDATAMODEL_H
#define REALDATAMODEL_H

#include "SessionModel.h"

//! The RealDataModel class is a model to store all imported RealDataItem's.

class BA_CORE_API_ RealDataModel : public SessionModel
{
    Q_OBJECT

public:
    explicit RealDataModel(QObject *parent = 0);
//    Qt::ItemFlags flags(const QModelIndex &index) const;

    QVector<SessionItem*> nonXMLData() const override;
};

#endif // REALDATAMODEL_H
