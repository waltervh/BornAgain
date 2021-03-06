// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/JobWorker.h
//! @brief     Defines class JobWorker
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef JOBWORKER_H
#define JOBWORKER_H

#include "WinDllMacros.h"
#include <QObject>

class Simulation;

//! The JobWorker class provides running the domain simulation in a thread.

class BA_CORE_API_ JobWorker : public QObject
{
    Q_OBJECT
public:
    JobWorker(const QString& identifier, Simulation* simulation);

    QString identifier() const;

    int progress() const;

    QString status() const;

    QString failureMessage() const;

    int simulationDuration() const;

signals:
    void started();
    void finished();
    void progressUpdate();

public slots:
    void start();
    void terminate();

private:
    bool updateProgress(int percentage_done);

    QString m_identifier;
    Simulation* m_simulation;
    int m_percentage_done;
    QString m_job_status;
    bool m_terminate_request_flag;
    QString m_failure_message;
    int m_simulation_duration;
};

#endif // JOBWORKER_H
