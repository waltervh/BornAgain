// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/CommonWidgets/DockWidgetInfo.h
//! @brief     Defines class DockWidgetInfo
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef DOCKWIDGETINFO_H
#define DOCKWIDGETINFO_H

#include "WinDllMacros.h"
#include <qnamespace.h>

class QDockWidget;
class QWidget;

//! Holds information about the widget and its dock.

class BA_CORE_API_ DockWidgetInfo
{
public:
    DockWidgetInfo();
    DockWidgetInfo(QDockWidget* dock, QWidget* widget, Qt::DockWidgetArea area);

    QDockWidget* dock();
    QWidget* widget();
    Qt::DockWidgetArea area();

private:
    QDockWidget* m_dock;
    QWidget* m_widget;
    Qt::DockWidgetArea m_area;
};

#endif //  DOCKSCONTROLLER_H
