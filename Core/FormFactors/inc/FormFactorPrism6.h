// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      FormFactors/inc/FormFactorPrism6.h
//! @brief     Defines class FormFactorPrism6.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef FORMFACTORPRISM6_H
#define FORMFACTORPRISM6_H
#include "IFormFactorBorn.h"

//! Formfactor of a prism based on a regular hexagonal.

class BA_CORE_API_ FormFactorPrism6 : public IFormFactorBorn
{
public:
    FormFactorPrism6(double height, double half_side);
    ~FormFactorPrism6() {}
    virtual FormFactorPrism6 *clone() const;

    virtual void accept(ISampleVisitor *visitor) const { visitor->visit(this); }

    virtual int getNumberOfStochasticParameters() const { return 2; }

    virtual double getHeight() const { return m_height; }

    virtual complex_t evaluate_for_q(const cvector_t& q) const;

protected:  
    virtual void init_parameters();

private:
    double m_height;
    double m_half_side;
    double m_root3; // Cached value of square root of 3
};

#endif // FORMFACTORPRISM6_H


