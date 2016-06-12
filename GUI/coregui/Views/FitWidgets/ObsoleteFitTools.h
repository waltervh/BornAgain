// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/FitWidgets/ObsoleteFitTools.h
//! @brief     Declares class ObsoleteFitTools
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef OBSOLETEFITTOOLS_H
#define OBSOLETEFITTOOLS_H

#include <QWidget>
#include "OutputData.h"
#include <memory>

class JobItem;
class JobModel;
class QHBoxLayout;
class QItemSelectionModel;
class QPushButton;
class RunFitManager;
class GUIFitObserver;
class QSlider;
class ObsoleteRealDataWindow;

class ObsoleteFitTools : public QWidget
{
    Q_OBJECT

public:
    ObsoleteFitTools(JobModel *jobModel, QWidget *parent = 0);

    void setCurrentItem(JobItem *item, QItemSelectionModel *selection);

public slots:
    void onStartClick();
    void onFittingStarted();
    void onFittingFinished();
    void onStopClicked();
    void onError(const QString &text);
    void onUpdatePlots(OutputData<double>*sim, OutputData<double>*chi2);
    void onUpdateParameters(const QStringList &parameters, QVector<double> values);
    void onRealData();

private:
    JobModel *m_jobModel;
    JobItem *m_currentJobItem;
    QItemSelectionModel *m_selectionModel;
    QPushButton *m_startButton;
    QPushButton *m_stopButton;
    QSlider *m_intervalSlider;
    QPushButton *m_realData;
    RunFitManager *m_manager;
    std::shared_ptr<GUIFitObserver> m_observer;
    ObsoleteRealDataWindow *m_realDataWindow;
};

#endif
