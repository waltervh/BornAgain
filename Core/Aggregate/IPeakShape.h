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

template <class T> class IntegratorReal;

//! Pure virtual interface class that defines the peak shape of a Bragg peak.
//!
//! @ingroup samples_internal

class BA_CORE_API_ IPeakShape : public ISample
{
public:
    virtual ~IPeakShape();

    virtual IPeakShape* clone() const=0;

    //! Evaluates the peak shape at q from a reciprocal lattice point at q_lattice_point
    virtual double evaluate(const kvector_t q, const kvector_t q_lattice_point) const=0;

    //! Indicates if the peak shape encodes angular disorder, in which case all peaks in a
    //! spherical shell are needed
    virtual bool angularDisorder() const { return false; }
};


//! Class that implements an isotropic Gaussian peak shape of a Bragg peak.
//!
//! @ingroup samples_internal

class BA_CORE_API_ IsotropicGaussPeakShape : public IPeakShape
{
public:
    IsotropicGaussPeakShape(double max_intensity, double domainsize);
    ~IsotropicGaussPeakShape() override;

    IsotropicGaussPeakShape* clone() const override;

    void accept(INodeVisitor* visitor) const override { visitor->visit(this); }

    double evaluate(const kvector_t q, const kvector_t q_lattice_point) const override;
private:
    double evaluate(const kvector_t q) const;
    double m_max_intensity;
    double m_domainsize;
};

//! Class that implements an isotropic Lorentzian peak shape of a Bragg peak.
//!
//! @ingroup samples_internal

class BA_CORE_API_ IsotropicLorentzPeakShape : public IPeakShape
{
public:
    IsotropicLorentzPeakShape(double max_intensity, double domainsize);
    ~IsotropicLorentzPeakShape() override;

    IsotropicLorentzPeakShape* clone() const override;

    void accept(INodeVisitor* visitor) const override { visitor->visit(this); }

    double evaluate(const kvector_t q, const kvector_t q_lattice_point) const override;
private:
    double evaluate(const kvector_t q) const;
    double m_max_intensity;
    double m_domainsize;
};

//! Class that implements a peak shape that is Gaussian in the radial direction and
//! uses the von Mises-Fisher distribution in the angular direction.
//!
//! @ingroup samples_internal

class BA_CORE_API_ GaussFisherPeakShape : public IPeakShape
{
public:
    GaussFisherPeakShape(double max_intensity, double radial_size, double kappa);
    ~GaussFisherPeakShape() override;

    GaussFisherPeakShape* clone() const override;

    void accept(INodeVisitor* visitor) const override { visitor->visit(this); }

    double evaluate(const kvector_t q, const kvector_t q_lattice_point) const override;

    bool angularDisorder() const override { return true; }
private:
    double m_max_intensity;
    double m_radial_size;
    double m_kappa;
};

//! Class that implements a peak shape that is Lorentzian in the radial direction and
//! uses the von Mises-Fisher distribution in the angular direction.
//!
//! @ingroup samples_internal

class BA_CORE_API_ LorentzFisherPeakShape : public IPeakShape
{
public:
    LorentzFisherPeakShape(double max_intensity, double radial_size, double kappa);
    ~LorentzFisherPeakShape() override;

    LorentzFisherPeakShape* clone() const override;

    void accept(INodeVisitor* visitor) const override { visitor->visit(this); }

    double evaluate(const kvector_t q, const kvector_t q_lattice_point) const override;

    bool angularDisorder() const override { return true; }
private:
    double m_max_intensity;
    double m_radial_size;
    double m_kappa;
};

//! Class that implements a peak shape that is Gaussian in the radial direction and a
//! convolution of a von Mises-Fisher distribution with a von Mises distribution on the
//! two-sphere
//!
//! @ingroup samples_internal

class BA_CORE_API_ VonMisesFisherGaussPeakShape : public IPeakShape
{
public:
    VonMisesFisherGaussPeakShape(double max_intensity, double radial_size, kvector_t zenith,
                                 double kappa_1, double kappa_2);
    ~VonMisesFisherGaussPeakShape() override;

    VonMisesFisherGaussPeakShape* clone() const override;

    void accept(INodeVisitor* visitor) const override { visitor->visit(this); }

    double evaluate(const kvector_t q, const kvector_t q_lattice_point) const override;

    bool angularDisorder() const override { return true; }
private:
    double integrand(double phi) const;
    double m_max_intensity;
    double m_radial_size;
    kvector_t m_zenith;
    double m_kappa_1, m_kappa_2;
    mutable double m_theta, m_phi;
    mutable kvector_t m_ux, m_uy, m_up;
#ifndef SWIG
    std::unique_ptr<IntegratorReal<VonMisesFisherGaussPeakShape>> mP_integrator;
#endif
};

//! Class that implements a peak shape that is a convolution of a von Mises-Fisher distribution
//! with a 3d Gaussian
//!
//! @ingroup samples_internal

class BA_CORE_API_ VonMisesGaussPeakShape : public IPeakShape
{
public:
    VonMisesGaussPeakShape(double max_intensity, double radial_size, kvector_t zenith,
                           double kappa);
    ~VonMisesGaussPeakShape() override;

    VonMisesGaussPeakShape* clone() const override;

    void accept(INodeVisitor* visitor) const override { visitor->visit(this); }

    double evaluate(const kvector_t q, const kvector_t q_lattice_point) const override;

    bool angularDisorder() const override { return true; }
private:
    double integrand(double phi) const;
    double m_max_intensity;
    double m_radial_size;
    kvector_t m_zenith;
    double m_kappa;
    mutable double m_theta, m_phi, m_qr;
    mutable kvector_t m_ux, m_uy, m_p;
#ifndef SWIG
    std::unique_ptr<IntegratorReal<VonMisesGaussPeakShape>> mP_integrator;
#endif
};


#endif // IPEAKSHAPE_H
