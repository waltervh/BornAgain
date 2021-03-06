// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/SoftParticle/FormFactorSphereGaussianRadius.h
//! @brief     Defines and implements class FormFactorSphereGaussianRadius.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef FORMFACTORSPHEREGAUSSIANRADIUS_H
#define FORMFACTORSPHEREGAUSSIANRADIUS_H

#include "FormFactorFullSphere.h"
#include <memory>

//! A sphere with gaussian radius distribution.
//! @ingroup softParticle

class BA_CORE_API_ FormFactorSphereGaussianRadius : public IFormFactorBorn
{
public:
    FormFactorSphereGaussianRadius(double mean, double sigma);

    FormFactorSphereGaussianRadius* clone() const override final {
        return new FormFactorSphereGaussianRadius(m_mean, m_sigma); }

    void accept(INodeVisitor* visitor) const override final { visitor->visit(this); }

    double radialExtension() const override final { return m_mean; }

    complex_t evaluate_for_q(cvector_t q) const override final;

protected:
    void onChange() override final;

private:
    double calculateMeanR3() const;

    double m_mean; //!< This is the mean radius
    double m_sigma;
    double m_mean_r3; //!< This is the radius that gives the mean volume
    std::unique_ptr<FormFactorFullSphere> P_ff_sphere;
};

#endif // FORMFACTORSPHEREGAUSSIANRADIUS_H
