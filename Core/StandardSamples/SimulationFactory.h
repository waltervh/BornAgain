// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/StandardSamples/SimulationFactory.h
//! @brief     Defines class SimulationFactory.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef SIMULATIONFACTORY_H
#define SIMULATIONFACTORY_H

#include "IFactory.h"
#include "GISASSimulation.h"
#include <string>

//! Registry to create standard pre-defined simulations.
//! Used in functional tests, performance measurements, etc.
//! @ingroup standard_samples

class BA_CORE_API_ SimulationFactory : public IFactory<std::string, Simulation>
{
public:
    SimulationFactory();
};

#endif // SIMULATIONFACTORY_H
