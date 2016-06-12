// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/utils/GUIFutest.h
//! @brief     Declares class GUIFutest
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef GUIFUNCTIONALTEST_H
#define GUIFUNCTIONALTEST_H

#include "WinDllMacros.h"
#include "IFutest.h"
#include "OutputData.h"
#include <string>

class GISASSimulation;

//! @class GUIFutest
//! @ingroup standard_samples
//! @brief GUI functional test  compares results of the reference simulation with
//! the one obtained through domain->GUI->domain convertion. Normally invoked by
//! FunctionalMultiTest.

class BA_CORE_API_ GUIFutest : public IFutest
{
public:
    GUIFutest(const std::string &name, const std::string &description,
                      GISASSimulation *reference_simulation, double threshold);
    virtual ~GUIFutest();

    virtual void runTest();
    virtual int analyseResults();

    const OutputData<double>* getOutputData() const;

    virtual void printResults(std::ostream &ostr) const;

private:
    void createDomainSimulation();

    GISASSimulation *m_reference_simulation;
    GISASSimulation *m_domain_simulation;
    double m_threshold;
    double m_difference;
};

#endif

