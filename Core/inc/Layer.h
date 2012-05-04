#ifndef LAYER_H
#define LAYER_H
// ********************************************************************
// * The BornAgain project                                            *
// * Simulation of neutron and x-ray scattering at grazing incidence  *
// *                                                                  *
// * LICENSE AND DISCLAIMER                                           *
// * Lorem ipsum dolor sit amet, consectetur adipiscing elit.  Mauris *
// * eget quam orci. Quisque  porta  varius  dui,  quis  posuere nibh *
// * mollis quis. Mauris commodo rhoncus porttitor.                   *
// ********************************************************************
//! @file   Layer.h
//! @brief  Definition of Layer class
//! @author Scientific Computing Group at FRM II
//! @date   01.04.2012

#include "ISample.h"
#include "IMaterial.h"
#include "Types.h"
#include "HomogeneousMaterial.h"


//- -------------------------------------------------------------------
/// @class Layer
/// @brief Definition of Layer with thickness and pointer to the material
//- -------------------------------------------------------------------
class Layer : public ISample
{
public:
    Layer();
    Layer(const Layer &other);
    Layer &operator=(const Layer &other);
    virtual ~Layer();

    //! make layer's clone
    virtual Layer *clone() const;

    /// set layer thickness in _angstrom_
    virtual void setThickness(double thickness);

    /// return layer thickness in _angstrom_
    virtual double getThickness() const { return m_thickness; }

    /// set material to the layer
    /// @param p_material   pointer to the material
    virtual void setMaterial(const IMaterial* p_material) { p_material ? mp_material = p_material : throw NullPointerException("The material doesn't exist"); }

    /// set material of given thickness to the layer
    /// @param p_material   pointer to the material of layer
    /// @param thickness    thickness of the material in angstrom
    virtual void setMaterial(const IMaterial* p_material, double thickness);

    /// return layer's material
    virtual const IMaterial* getMaterial() const { return mp_material; }

    /// return refractive index of the layer's material
    virtual complex_t getRefractiveIndex() const { return (dynamic_cast<const HomogeneousMaterial *>(mp_material))->getRefractiveIndex(); }

private:
    const IMaterial* mp_material;    ///< pointer to the material
    double m_thickness;              ///< layer thickness in _angstrom_
};


#endif // LAYER_H
