// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Fit/Minimizer/FitKernel.cpp
//! @brief     Implements class FitKernel.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "FitKernel.h"
#include "FitKernelImp.h"
#include "MinimizerFactory.h"
#include "FitParameter.h"

namespace {
const std::string default_minimizer = "Minuit2";
const std::string default_algorithm = "Migrad";
}

FitKernel::FitKernel()
    : m_impl(new FitKernelImp)
{
    setMinimizer(default_minimizer, default_algorithm);
}

FitKernel::~FitKernel()
{

}

void FitKernel::setMinimizer(const std::string &minimizerName, const std::string &algorithmName)
{
    m_impl->setMinimizer(MinimizerFactory::createMinimizer(minimizerName, algorithmName));
}

void FitKernel::setMinimizer(IMinimizer *minimizer)
{
    if(!minimizer)
        throw std::runtime_error("FitKernel::setMinimizer() -> Error. Nullptr minimizer");

    m_impl->setMinimizer(minimizer);
}

const IMinimizer *FitKernel::minimizer() const
{
    return m_impl->minimizer();
}

void FitKernel::addFitParameter(const std::string& name, double value,
                     const AttLimits& limits, double step)
{
    if(step <= 0.0)
        throw std::runtime_error("FitKernel::addFitParameter() -> Error. Step can't be <= 0.0.");

    m_impl->addFitParameter(new FitParameter(name, value, limits, step));
}


void FitKernel::setObjectiveFunction(objective_function_t func)
{
    m_impl->setObjectiveFunction(func);
}

void FitKernel::setGradientFunction(gradient_function_t func, int ndatasize)
{
    m_impl->setGradientFunction(func, ndatasize);
}

void FitKernel::minimize()
{
    m_impl->minimize();
}

std::string FitKernel::reportResults() const
{
    return m_impl->reportResults();
}

FitParameterSet *FitKernel::fitParameters()
{
    return const_cast<FitParameterSet *>(static_cast<const FitKernel*>(this)->fitParameters());
}

const FitParameterSet *FitKernel::fitParameters() const
{
    return m_impl->fitParameters();
}
