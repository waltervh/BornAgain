// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/JobWidgets/JobViewDocks.h
//! @brief     Declares class JobViewDocks
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef JOBVIEWDOCKS_H
#define JOBVIEWDOCKS_H

#include "WinDllMacros.h"
#include "JobViewFlags.h"
#include <QObject>
#include <QVector>

class QDockWidget;
class JobView;

//! The JobViewDocks class assists JobView in holding all main job widgets and corresponding
//! dock containers.
//! Provides Job Activities switch logic for all of (JobSelectorWidget, JobOutputDataWidget,
//! JobRealTimeWidget and FitPanelWidget).

class BA_CORE_API_ JobViewDocks : public QObject {
    Q_OBJECT

public:
    JobViewDocks(JobView *parent = 0);

    void initViews(class JobModel *jobModel);

    class JobRealTimeWidget *jobRealTimeWidget() { return m_jobRealTimeWidget;}
    class FitActivityPanel *fitActivityPanel() { return m_fitActivityPanel; }
    class JobSelectorWidget *jobSelector() { return m_jobSelector; }
    class JobOutputDataWidget *jobOutputDataWidget() { return m_jobOutputDataWidget; }

    void setActivity(int activity);
    void setItem(class JobItem *jobItem);

public slots:
    void onResetLayout();
    void onToggleJobSelector();

private:
    QWidget *jobWidget(JobViewFlags::Dock dockId);
    QDockWidget *dock(JobViewFlags::Dock dockId);
    QWidget *centralWidget();
    void initJobWidgets(class JobModel *jobModel);
    void initDocks();

    class JobSelectorWidget *m_jobSelector;
    class JobOutputDataWidget *m_jobOutputDataWidget;
    class JobRealTimeWidget *m_jobRealTimeWidget;
    class FitActivityPanel *m_fitActivityPanel;

    QVector<QWidget *> m_jobWidgets;
    QVector<QDockWidget *> m_dockWidgets;

    JobView *m_jobView;
};

#endif