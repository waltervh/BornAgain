// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/MaskWidgets/MaskContainerView.h
//! @brief     Defines MaskContainerView class
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef MASKCONTAINERVIEW_H
#define MASKCONTAINERVIEW_H

#include "IShape2DView.h"
#include "SizeHandleElement.h"
#include <QMap>

//! The MaskContainerView is nothing move than just transparent rectangle to cover axes area
//! of ColorMapPlot inside MaskGraphicsScene. The goal of this rectangle is to hide all MaskViews
//! if they are going outside of ColorMapPlot.
//!
//! The size of the rectangle always matches axes viewport at any zoom level.
//! All MasksViews are added to MaskContainerView as children.

class BA_CORE_API_ MaskContainerView : public IShape2DView
{
    Q_OBJECT

public:
    int type() const { return MaskEditorHelper::MASKCONTAINER; }
    MaskContainerView();

protected slots:
    void update_view();

protected:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*);
};

#endif // MASKCONTAINERVIEW_H
