"""
Example demonstrates how to fit several sample parameters with one fit parameter.
Our sample represents cylindrical particles in rectangular lattice. We are going
to fit the data, assuming that cylinder radius, height and both lattice lengths
are the same.

"Real data" was generated for
cylinder_radius = cylinder_height = lattice_length1 = lattice_length2 = 8*nm

Then we create a fit setup, where one fit parameter will steer all corresponding
sample parameters, namely

/MultiLayer/Layer0/ParticleLayout/Interference2DLattice/LatticeLength1
/MultiLayer/Layer0/ParticleLayout/Interference2DLattice/LatticeLength2
/MultiLayer/Layer0/ParticleLayout/Particle/Cylinder/Radius
/MultiLayer/Layer0/ParticleLayout/Particle/Cylinder/Height
"""

from matplotlib import pyplot as plt
import math
import random
import bornagain as ba
from bornagain import deg, angstrom, nm


def get_sample(radius=5*nm, height=5*nm, lattice_constant=10*nm):
    """
    Returns a sample with cylinders on a substrate,
    forming a rectangular lattice.
    """
    m_air = ba.HomogeneousMaterial("Air", 0.0, 0.0)
    m_substrate = ba.HomogeneousMaterial("Substrate", 6e-6, 2e-8)
    m_particle = ba.HomogeneousMaterial("Particle", 6e-4, 2e-8)

    ff = ba.FormFactorCylinder(radius, height)
    cylinder = ba.Particle(m_particle, ff)
    particle_layout = ba.ParticleLayout()
    particle_layout.addParticle(cylinder)

    interference = ba.InterferenceFunction2DLattice.\
        createSquare(lattice_constant)
    pdf = ba.FTDecayFunction2DCauchy(50*nm, 50*nm)
    interference.setDecayFunction(pdf)

    particle_layout.setInterferenceFunction(interference)

    air_layer = ba.Layer(m_air)
    air_layer.addLayout(particle_layout)
    substrate_layer = ba.Layer(m_substrate, 0)
    multi_layer = ba.MultiLayer()
    multi_layer.addLayer(air_layer)
    multi_layer.addLayer(substrate_layer)
    return multi_layer


def get_simulation():
    """
    Create and return GISAXS simulation with beam and detector defined
    """
    simulation = ba.GISASSimulation()
    simulation.setDetectorParameters(100, -1.0*deg, 1.0*deg,
                                     100, 0.0*deg, 2.0*deg)
    simulation.setBeamParameters(1.0*angstrom, 0.2*deg, 0.0*deg)
    return simulation


def create_real_data():
    """
    Generating "real" data by adding noise to the simulated data.
    """
    sample = get_sample(8.0*nm, 8.0*nm, 8.0*nm)

    simulation = get_simulation()
    simulation.setSample(sample)

    simulation.runSimulation()
    real_data = simulation.getIntensityData()

    # spoiling simulated data with the noise to produce "real" data
    noise_factor = 0.1
    for i in range(0, real_data.getTotalNumberOfBins()):
        amplitude = real_data.getBinContent(i)
        sigma = noise_factor*math.sqrt(amplitude)
        noisy_amplitude = random.gauss(amplitude, sigma)
        if noisy_amplitude < 0.1:
            noisy_amplitude = 0.1
        real_data.setBinContent(i, noisy_amplitude)
    return real_data


def run_fitting():
    """
    main function to run fitting
    """
    simulation = get_simulation()
    sample = get_sample()
    simulation.setSample(sample)

    print(simulation.treeToString())
    print(simulation.parametersToString())

    real_data = create_real_data()

    fit_suite = ba.FitSuite()
    fit_suite.addSimulationAndRealData(simulation, real_data)
    fit_suite.initPrint(10)

    draw_observer = ba.DefaultFitObserver(draw_every_nth=10)
    fit_suite.attachObserver(draw_observer)

    # this fit parameter fits 4 sample parameter with one value
    fit_suite.addFitParameter("*2DLattice/LatticeLength*", 10.*nm).\
        setLimited(4., 12.).addPattern("*Cylinder/Radius").\
        addPattern("*Cylinder/Height")

    # alternatively, following syntax is possible
    # fitPar = ba.FitParameter("*2DLattice/LatticeLength*",
    #                          10.*nm, ba.AttLimits.limited(4., 12.))
    # fitPar.addPattern("*Cylinder/Radius").addPattern("*Cylinder/Height")
    # fit_suite.addFitParameter(fitPar)

    # prints defined fit parameters and their relation to instrument parameters
    print(fit_suite.setupToString())

    # running fit
    print("Starting the fitting")
    fit_suite.runFit()

    print("Fitting completed.")
    print("chi2:", fit_suite.getChi2())
    for fitPar in fit_suite.fitParameters():
        print(fitPar.name(), fitPar.value(), fitPar.error())


if __name__ == '__main__':
    run_fitting()
    plt.show()
