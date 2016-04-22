// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      FormFactors/FormFactorzdodecahedron.cpp
//! @brief     Implements class FormFactorDodecahedron.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015-16
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "FormFactorDodecahedron.h"
#include "BornAgainNamespace.h"
#include "FormFactorBox.h"
#include "MathFunctions.h"


FormFactorDodecahedron::FormFactorDodecahedron(double edge)
    : FormFactorPolyhedron()
    , m_edge(edge)
{
    setName(BornAgain::FFDodecahedronType);
    registerParameter(BornAgain::Edge, &m_edge);
    onChange();
}

void FormFactorDodecahedron::onChange()
{
    double a = m_edge;
    kvector_t V[20] = {
        {  0.8506508083520399*a,                   0*a,  -1.113516364411607*a},
        {  0.2628655560595668*a,  0.8090169943749473*a,  -1.113516364411607*a},
        { -0.6881909602355868*a,                 0.5*a,  -1.113516364411607*a},
        { -0.6881909602355868*a,                -0.5*a,  -1.113516364411607*a},
        {  0.2628655560595668*a, -0.8090169943749473*a,  -1.113516364411607*a},
        {   1.376381920471174*a,                   0*a, -0.2628655560595667*a},
        {    0.42532540417602*a,   1.309016994374947*a, -0.2628655560595667*a},
        {  -1.113516364411607*a,  0.8090169943749475*a, -0.2628655560595667*a},
        {  -1.113516364411607*a, -0.8090169943749475*a, -0.2628655560595667*a},
        {    0.42532540417602*a,  -1.309016994374947*a, -0.2628655560595667*a},
        {  -1.376381920471174*a,                   0*a,  0.2628655560595667*a},
        {   -0.42532540417602*a,  -1.309016994374947*a,  0.2628655560595667*a},
        {   1.113516364411607*a, -0.8090169943749475*a,  0.2628655560595667*a},
        {   1.113516364411607*a,  0.8090169943749475*a,  0.2628655560595667*a},
        {   -0.42532540417602*a,   1.309016994374947*a,  0.2628655560595667*a},
        { -0.8506508083520399*a,                   0*a,   1.113516364411607*a},
        { -0.2628655560595668*a, -0.8090169943749473*a,   1.113516364411607*a},
        {  0.6881909602355868*a,                -0.5*a,   1.113516364411607*a},
        {  0.6881909602355868*a,                 0.5*a,   1.113516364411607*a},
        { -0.2628655560595668*a,  0.8090169943749473*a,   1.113516364411607*a} };
    m_faces.clear();
    // bottom:
    m_faces.push_back( PolyhedralFace( { V[ 0], V[ 4], V[ 3], V[ 2], V[ 1] } ) );
    // lower ring:
    m_faces.push_back( PolyhedralFace( { V[ 0], V[ 5], V[12], V[ 9], V[ 4] } ) );
    m_faces.push_back( PolyhedralFace( { V[ 4], V[ 9], V[11], V[ 8], V[ 3] } ) );
    m_faces.push_back( PolyhedralFace( { V[ 3], V[ 8], V[10], V[ 7], V[ 2] } ) );
    m_faces.push_back( PolyhedralFace( { V[ 2], V[ 7], V[14], V[ 6], V[ 1] } ) );
    m_faces.push_back( PolyhedralFace( { V[ 1], V[ 6], V[13], V[ 5], V[ 0] } ) );
     // upper ring:
    m_faces.push_back( PolyhedralFace( { V[ 8], V[11], V[16], V[15], V[10] } ) );
    m_faces.push_back( PolyhedralFace( { V[ 9], V[12], V[17], V[16], V[11] } ) );
    m_faces.push_back( PolyhedralFace( { V[ 5], V[13], V[18], V[17], V[12] } ) );
    m_faces.push_back( PolyhedralFace( { V[ 6], V[14], V[19], V[18], V[13] } ) );
    m_faces.push_back( PolyhedralFace( { V[ 7], V[10], V[15], V[19], V[14] } ) );
    // top:
    m_faces.push_back( PolyhedralFace( { V[15], V[16], V[17], V[18], V[19] } ) );
    assert_platonic();

    m_z_origin = -1.113516364411607*a;
    m_sym_Ci = true;

    FormFactorPolyhedron::precompute();
}

FormFactorDodecahedron* FormFactorDodecahedron::clone() const
{
    return new FormFactorDodecahedron(m_edge);
}

void FormFactorDodecahedron::accept(ISampleVisitor *visitor) const
{
    visitor->visit(this);
}