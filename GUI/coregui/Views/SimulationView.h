// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/SimulationView.h
//! @brief     Defines class SimulationView
//!
//! @homepage  http://bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef SIMULATIONVIEW_H
#define SIMULATIONVIEW_H

#include "WinDllMacros.h"
#include <QWidget>

class MainWindow;
class JobQueueModel;
class SampleModel;
class InstrumentModel;
class SimulationSetupWidget;
class StyledToolBar;

class BA_CORE_API_ SimulationView : public QWidget
{
    Q_OBJECT

public:
    enum ETabViewId { SIMULATION_SETUP, QUICK_SIMULATION};
    SimulationView(MainWindow *mainWindow);

    void updateSimulationViewElements();

public slots:
    void onRunSimulationShortcut();

private:
    JobQueueModel *m_jobQueueModel;
    SampleModel *m_sampleModel;
    InstrumentModel *m_instrumentModel;

    SimulationSetupWidget *m_simulationSetupWidget;
    StyledToolBar *m_toolBar;
};


#endif // SIMULATIONVIEW_H

