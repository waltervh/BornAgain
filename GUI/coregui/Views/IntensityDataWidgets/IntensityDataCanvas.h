// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/IntensityDataWidgets/IntensityDataCanvas.h
//! @brief     Defines class IntensityDataCanvas
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef INTENSITYDATACANVAS_H
#define INTENSITYDATACANVAS_H

#include "SessionItemWidget.h"

class SessionItem;
class IntensityDataItem;
class ColorMapCanvas;
class QAction;

//! The IntensityDataCanvas class represents IntensityDataItem as color map,
//! provides standard actions (reset view, save as) for external toolbars and context menus.

class BA_CORE_API_ IntensityDataCanvas : public NewSessionItemWidget
{
    Q_OBJECT
public:
    explicit IntensityDataCanvas(QWidget* parent = 0);

    void setItem(SessionItem* intensityItem);

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    QList<QAction*> actionList();

public slots:
    void onResetViewAction();
    void onSavePlotAction();
    void onMousePress(QMouseEvent *event);

private:
    IntensityDataItem* intensityDataItem();
    void initActions();

    ColorMapCanvas* m_colorMap;
    QAction* m_resetViewAction;
    QAction* m_savePlotAction;
};

#endif // INTENSITYDATACANVAS_H
