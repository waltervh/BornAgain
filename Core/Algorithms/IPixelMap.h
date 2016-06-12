// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Algorithms/IPixelMap.h
//! @brief     Declares interface IPixelMap.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef IPIXELMAP_H_
#define IPIXELMAP_H_

#include "Vectors3D.h"

//! @class IPixelMap
//! @ingroup simulation
//! @brief Interface for a function that maps [0,1]x[0,1] to the kvectors in a pixel.

class IPixelMap
{
public:
    virtual ~IPixelMap() {}

    virtual IPixelMap* clone() const=0;
    virtual IPixelMap* createZeroSizeMap(double x, double y) const=0;
    virtual kvector_t getK(double x, double y, double wavelength) const=0;
    virtual double getIntegrationFactor(double x, double y) const=0;
    virtual double getSolidAngle() const=0;
};

#endif /* IPIXELMAP_H_ */
