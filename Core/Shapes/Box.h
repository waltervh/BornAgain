// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Shapes/Box.h
//! @brief     Defines class Box.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BOX_H
#define BOX_H

#include "IShape.h"

class Box : public IShape
{
public:
    Box(double length, double width, double height);
    ~Box();
};

#endif // BOX_H
