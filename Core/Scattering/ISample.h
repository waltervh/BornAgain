// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Scattering/ISample.h
//! @brief     Defines interface class ISample.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef ISAMPLE_H
#define ISAMPLE_H

#include "ICloneable.h"
#include "INode.h"
#include <vector>

class Material;

//! Pure virtual base class for sample components and properties related to scattering.
//! @ingroup samples_internal

class BA_CORE_API_ ISample : public ICloneable, public INode
{
public:
    //! Returns a clone of this ISample object.
    ISample* clone() const override=0;

    //! Returns nullptr, unless overwritten to return a specific material.
    virtual const Material* material() const { return nullptr; }

    //! Returns set of unique materials contained in this ISample.
    std::vector<const Material*> containedMaterials() const;
};

#endif // ISAMPLE_H
