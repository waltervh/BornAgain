#ifndef INSTRUMENTTEST_H
#define INSTRUMENTTEST_H

#include "Units.h"
#include "Instrument.h"
#include "BornAgainNamespace.h"

class InstrumentTest : public ::testing::Test
{
 protected:
    InstrumentTest();
    virtual ~InstrumentTest();

    Instrument m_instrument;
    OutputData<double> m_data;
};


InstrumentTest::InstrumentTest()
{
    m_data.addAxis(BornAgain::PHI_AXIS_NAME, 10, 0., 10.);
    m_data.addAxis("theta_f", 20, 0., 20.);
}

InstrumentTest::~InstrumentTest()
{
}

TEST_F(InstrumentTest, InstrumentInitialState)
{
    EXPECT_EQ( 0.0, m_instrument.getBeam().getIntensity());
}


TEST_F(InstrumentTest, BeamManipulation)
{
    double lambda(1), alpha(-1), phi(1);
    double k = 2.*Units::PI/lambda;
    double x = k*std::cos(alpha) * std::cos(phi);
    double y = -k*std::cos(alpha) * std::sin(phi);
    double z = k*std::sin(alpha);
    m_instrument.setBeamParameters(lambda, -1.0*alpha, phi);
    EXPECT_DOUBLE_EQ(x, m_instrument.getBeam().getCentralK().x() );
    EXPECT_DOUBLE_EQ(y, m_instrument.getBeam().getCentralK().y() );
    EXPECT_DOUBLE_EQ(z, m_instrument.getBeam().getCentralK().z() );

    EXPECT_FALSE( m_instrument.getDetectorDimension()==2 );
    m_instrument.matchDetectorAxes(m_data);
    EXPECT_TRUE( m_instrument.getDetectorDimension()==2 );
    const IAxis &axis0 = m_instrument.getDetectorAxis(0);
    const IAxis &axis1 = m_instrument.getDetectorAxis(1);
    EXPECT_EQ( axis0.getName(), BornAgain::PHI_AXIS_NAME );
    EXPECT_EQ( axis0.getSize(), (size_t)10);
    EXPECT_STREQ( axis1.getName().c_str(), "theta_f" );
    EXPECT_EQ( axis1.getSize(), (size_t)20);

    m_instrument.setBeamIntensity(10);
    EXPECT_EQ( double(10), m_instrument.getBeamIntensity());
}

TEST_F(InstrumentTest, InstrumentClone)
{
    Instrument clone(m_instrument);
    EXPECT_EQ( size_t(0), clone.getDetectorDimension() );
    EXPECT_EQ( 0.0, clone.getBeamIntensity() );
}

#endif // INSTRUMENTTEST_H
