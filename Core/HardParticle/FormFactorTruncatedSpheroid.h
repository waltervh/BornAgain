// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/HardParticle/FormFactorTruncatedSpheroid.h
//! @brief     Defines class FormFactorTruncatedSpheroid.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef FORMFACTORTRUNCATEDSPHEROID_H
#define FORMFACTORTRUNCATEDSPHEROID_H

#include "IFormFactorBorn.h"
#include "IntegratorComplex.h"

//! A truncated spheroid.
//! An ellipsoid with two equal axis, truncated by a plane perpendicular to the third axis.
//! @ingroup hardParticle

class BA_CORE_API_ FormFactorTruncatedSpheroid : public IFormFactorBorn
{
public:
    FormFactorTruncatedSpheroid(double radius, double height, double height_flattening,
                                double dh=0.0);

    FormFactorTruncatedSpheroid* clone() const override final {
        return new FormFactorTruncatedSpheroid(m_radius, m_height, m_height_flattening, m_dh); }
    void accept(INodeVisitor* visitor) const override final { visitor->visit(this); }

    double getRadius() const { return m_radius; }
    double getHeight() const { return m_height; }
    double getHeightFlattening() const { return m_height_flattening; }
    double getRemovedTop() const { return m_dh; }

    double radialExtension() const override final { return m_radius; }

    complex_t evaluate_for_q(cvector_t q) const override final;

protected:
    IFormFactor* sliceFormFactor(ZLimits limits, const IRotation& rot,
                                 kvector_t translation) const override final;

    void onChange() override final;

private:
    bool check_initialization() const;
    complex_t Integrand(double Z) const;

    double m_radius;
    double m_height;
    double m_height_flattening;
    double m_dh;
    mutable cvector_t m_q;

#ifndef SWIG
    std::unique_ptr<IntegratorComplex<FormFactorTruncatedSpheroid>> mP_integrator;
#endif
};

#endif // FORMFACTORTRUNCATEDSPHEROID_H
