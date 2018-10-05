// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Aggregate/IPeakShape.h
//! @brief     Defines the interface IPeakShape and subclasses.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef IPEAKSHAPE_H
#define IPEAKSHAPE_H

#include "ISample.h"
#include "Vectors3D.h"

//! Pure virtual interface class that defines the peak shape of a Bragg peak.
//!
//! @ingroup samples_internal

class BA_CORE_API_ IPeakShape : public ISample
{
public:
    virtual ~IPeakShape();

    virtual IPeakShape* clone() const=0;

    //! Evaluates the peak shape at displacement q from the center at 0
    virtual double evaluate(const kvector_t q) const=0;

    //! Returns the thickness in the z-direction
    virtual double thickness_z() const=0;
};


//! Class that implements a Gaussian peak shape of a Bragg peak.
//!
//! @ingroup samples_internal

class BA_CORE_API_ GaussPeakShape : public IPeakShape
{
public:
    GaussPeakShape(double domainsize);
    ~GaussPeakShape() override;

    GaussPeakShape* clone() const override;

    void accept(INodeVisitor* visitor) const override { visitor->visit(this); }

    double evaluate(const kvector_t q) const override;

    double thickness_z() const override;
private:
    double m_domainsize;
};

#endif // IPEAKSHAPE_H
