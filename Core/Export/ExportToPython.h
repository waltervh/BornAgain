// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Export/ExportToPython.h
//! @brief     Defines ExportToPython namespace.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef EXPORTTOPYTHON_H
#define EXPORTTOPYTHON_H

#include "WinDllMacros.h"
#include <string>

class MultiLayer;
class Simulation;

//! Contains main methods to generate Python scripts from Core simulation objects.

namespace ExportToPython {

BA_CORE_API_ std::string generateSampleCode(const MultiLayer& multilayer);
BA_CORE_API_ std::string generateSimulationCode(const Simulation& simulation);
BA_CORE_API_ std::string generatePyExportTest(const Simulation& simulation);

}

#endif  //EXPORTTOPYTHON_H
