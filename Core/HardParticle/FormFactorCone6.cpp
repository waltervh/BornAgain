// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/HardParticle/FormFactorCone6.cpp
//! @brief     Implements class FormFactorCone6.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "FormFactorCone6.h"
#include "BornAgainNamespace.h"
#include "Exceptions.h"
#include "MathFunctions.h"
#include "MathConstants.h"
#include "Pyramid6.h"
#include "RealParameter.h"

const PolyhedralTopology FormFactorCone6::topology = {
    {
        { {  5,  4,  3,  2,  1,  0 }, true },
        { {  0,  1,  7,  6 }, false },
        { {  1,  2,  8,  7 }, false },
        { {  2,  3,  9,  8 }, false },
        { {  3,  4, 10,  9 }, false },
        { {  4,  5, 11, 10 }, false },
        { {  5,  0,  6, 11 }, false },
        { {  6,  7,  8,  9, 10, 11 }, true }
    }, false };

//! Constructor of a truncated pyramid, based on a regular hexagon
//! @param base_edge: Edge of the regular hexagonal base in nanometers
//! @param height: height of a truncated pyramid in nanometers
//! @param alpha: dihedral angle in radians between base and facet
FormFactorCone6::FormFactorCone6(double base_edge, double height, double alpha)
    : FormFactorPolyhedron()
    , m_base_edge(base_edge)
    , m_height(height)
    , m_alpha(alpha)
{
    setName(BornAgain::FFCone6Type);
    registerParameter(BornAgain::BaseEdge, &m_base_edge).setUnit(BornAgain::UnitsNm)
        .setNonnegative();
    registerParameter(BornAgain::Height, &m_height).setUnit(BornAgain::UnitsNm)
        .setNonnegative();
    registerParameter(BornAgain::Alpha, &m_alpha).setUnit(BornAgain::UnitsRad)
        .setLimited(0., M_PI_2);
    onChange();
}

IFormFactor*FormFactorCone6::sliceFormFactor(ZLimits limits, const IRotation& rot,
                                             kvector_t translation) const
{
    auto effects = computeSlicingEffects(limits, translation, m_height);
    double dbase_edge = effects.dz_bottom*MathFunctions::cot(m_alpha);
    FormFactorCone6 slicedff(m_base_edge - dbase_edge,
                             m_height - effects.dz_bottom - effects.dz_top, m_alpha);
    return CreateTransformedFormFactor(slicedff, rot, effects.position);
}

void FormFactorCone6::onChange()
{
    double cot_alpha = MathFunctions::cot(m_alpha);
    if( !std::isfinite(cot_alpha) || cot_alpha<0 )
        throw Exceptions::OutOfBoundsException("pyramid angle alpha out of bounds");
    double r = cot_alpha*2/sqrt(3) * m_height / m_base_edge; // L(top)/L(base)
    if ( r > 1 ) {
        std::ostringstream ostr;
        ostr << "Incompatible parameters in Cone6 ";
        ostr << "(base_edge=" << m_base_edge;
        ostr << ", height:" << m_height;
        ostr << ", alpha[rad]:" << m_alpha << ")";
        throw Exceptions::ClassInitializationException(ostr.str());
    }
    mP_shape.reset(new Pyramid6(m_base_edge, m_height, m_alpha));

    double a = m_base_edge;
    double as = a/2;
    double ac = a*sqrt(3)/2;
    double b = a * (1-r);
    double bs = b/2;
    double bc = b*sqrt(3)/2;

    double zcom = m_height * ( .5 - 2*r/3 + r*r/4 ) / ( 1 - r + r*r/3 ); // center of mass

    setPolyhedron( topology, -zcom, {
        // base:
        {  a,   0., -zcom },
        {  as,  ac, -zcom },
        { -as,  ac, -zcom },
        { -a,   0., -zcom },
        { -as, -ac, -zcom },
        {  as, -ac, -zcom },
        // top:
        {  b,   0., m_height-zcom },
        {  bs,  bc, m_height-zcom },
        { -bs,  bc, m_height-zcom },
        { -b,   0., m_height-zcom },
        { -bs, -bc, m_height-zcom },
        {  bs, -bc, m_height-zcom } } );
}
