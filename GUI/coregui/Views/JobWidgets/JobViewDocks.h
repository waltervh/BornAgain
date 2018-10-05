// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/JobWidgets/JobViewDocks.h
//! @brief     Defines class JobViewDocks
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef JOBVIEWDOCKS_H
#define JOBVIEWDOCKS_H

#include "DocksController.h"

class JobView;
class JobSelectorWidget;
class JobOutputDataWidget;
class JobRealTimeWidget;
class FitActivityPanel;
class JobMessagePanel;
class JobModel;

//! The JobViewDocks class assists JobView in holding all main job widgets and corresponding
//! dock containers.

//! It's main method setActivity handles visibility logic for all of (JobSelectorWidget,
//! JobOutputDataWidget, JobRealTimeWidget and FitPanelWidget).

class BA_CORE_API_ JobViewDocks : public DocksController
{
    Q_OBJECT

public:
    JobViewDocks(JobView* parent = nullptr);

    void initViews(JobModel* jobModel);

    JobRealTimeWidget* jobRealTimeWidget();
    FitActivityPanel* fitActivityPanel();
    JobSelectorWidget* jobSelector();
    JobOutputDataWidget* jobOutputDataWidget();
    JobMessagePanel* jobMessagePanel();

    void setActivity(int activity);
    void setItem(class JobItem* jobItem);

public slots:
    void onResetLayout() override;
    void onToggleJobSelector();

private:
    JobSelectorWidget* m_jobSelector;
    JobOutputDataWidget* m_jobOutputDataWidget;
    JobRealTimeWidget* m_jobRealTimeWidget;
    FitActivityPanel* m_fitActivityPanel;
    JobMessagePanel* m_jobMessagePanel;
    JobView* m_jobView;
};

#endif // JOBVIEWDOCKS_H
