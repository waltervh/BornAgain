// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/TestMachinery/SubtestRegistry.cpp
//! @brief     Implements different registries for subtests of functional tests.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "BornAgainNamespace.h"
#include "FormFactors.h"
#include "SubtestRegistry.h"


// ************************************************************************** //
TestFTDistribution2DRegistry::TestFTDistribution2DRegistry()
// ************************************************************************** //
{
    add(BornAgain::FTDistribution2DCauchyType, new FTDistribution2DCauchy(0.5, 1.0));
    add(BornAgain::FTDistribution2DGaussType, new FTDistribution2DGauss(0.5, 1.0));
    add(BornAgain::FTDistribution2DGateType, new FTDistribution2DGate(0.5, 1.0));
    add(BornAgain::FTDistribution2DConeType, new FTDistribution2DCone(0.5, 1.0));
    add(BornAgain::FTDistribution2DVoigtType, new FTDistribution2DVoigt(0.5, 1.0, 0.2));
}


// ************************************************************************** //
TestFormFactorsRegistry::TestFormFactorsRegistry()
// ************************************************************************** //
{
    add(BornAgain::FFAnisoPyramidType,
        new FormFactorAnisoPyramid(10.0, 20.0, 5.0, Units::deg2rad(54.73 )));

    add(BornAgain::FFBoxType,
        new FormFactorBox(10.0, 20.0, 5.0));

    add(BornAgain::FFConeType,
        new FormFactorCone(5.0, 6.0, Units::deg2rad(54.73 )));

    add(BornAgain::FFCone6Type,
        new FormFactorCone6(2./sqrt(3.)*5.0, 5.0, Units::deg2rad(54.73)));

    add(BornAgain::FFCuboctahedronType,
        new FormFactorCuboctahedron(10.0, 5.0, 1.0, Units::deg2rad(54.73 )));

    add(BornAgain::FFCylinderType,
        new FormFactorCylinder(5.0, 10.0));

    add(BornAgain::FFDodecahedronType,
        new FormFactorDodecahedron(5.0));

    add(BornAgain::FFEllipsoidalCylinderType,
        new FormFactorEllipsoidalCylinder(5.0, 10.0, 15.0));

    add(BornAgain::FFFullSphereType,
        new FormFactorFullSphere(5.0));

    add(BornAgain::FFFullSpheroidType,
        new FormFactorFullSpheroid(5.0, 10.0));

    add(BornAgain::FFHemiEllipsoidType,
        new FormFactorHemiEllipsoid(5.0, 10.0, 15.0));

    add(BornAgain::FFIcosahedronType,
        new FormFactorIcosahedron(10.0));

    add(BornAgain::FFPrism3Type,
        new FormFactorPrism3(10.0, 5.0));

    add(BornAgain::FFPrism6Type,
        new FormFactorPrism6(2./sqrt(3.)*5.0, 5.0));

    add(BornAgain::FFPyramidType,
        new FormFactorPyramid(10.0, 5.0, Units::deg2rad(54.73 )));

    add(BornAgain::FFRipple1Type,
        new FormFactorRipple1(100.0, 20.0, 4.0));

    add(BornAgain::FFRipple2Type,
        new FormFactorRipple2(100.0, 20.0, 4.0, 0.0));

    add(BornAgain::FFTetrahedronType,
        new FormFactorTetrahedron(10.0, 4.0, Units::deg2rad(54.73 )));

    add(BornAgain::FFTruncatedCubeType,
        new FormFactorTruncatedCube(15.0, 6.0));

    add(BornAgain::FFTruncatedSphereType,
        new FormFactorTruncatedSphere(5.0, 7.0));

    add(BornAgain::FFTruncatedSpheroidType,
        new FormFactorTruncatedSpheroid(5.0, 7.0, 1.0));
}
