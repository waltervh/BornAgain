"""
Mixture of cylinders and prisms without interference
"""
import numpy
import matplotlib
import pylab
from bornagain import *

phi_min, phi_max = -1.0, 1.0
alpha_min, alpha_max = 0.0, 2.0


def get_sample():
    """
    Build and return the sample representing cylinders and prisms on top of
    substrate without interference.
    """
    # defining materials
    m_air = HomogeneousMaterial("Air", 0.0, 0.0)
    m_substrate = HomogeneousMaterial("Substrate", 6e-6, 2e-8)
    m_particle = HomogeneousMaterial("Particle", 6e-4, 2e-8)

    # collection of particles
    cylinder_ff = FormFactorCylinder(5*nanometer, 5*nanometer)
    cylinder = Particle(m_particle, cylinder_ff)
    prism_ff = FormFactorPrism3(10*nanometer, 5*nanometer)
    prism = Particle(m_particle, prism_ff)
    particle_layout = ParticleLayout()
    particle_layout.addParticle(cylinder, 0.0, 0.5)
    particle_layout.addParticle(prism, 0.0, 0.5)
    interference = InterferenceFunctionNone()
    particle_layout.addInterferenceFunction(interference)

    # air layer with particles and substrate form multi layer
    air_layer = Layer(m_air)
    air_layer.addLayout(particle_layout)
    substrate_layer = Layer(m_substrate)
    multi_layer = MultiLayer()
    multi_layer.addLayer(air_layer)
    multi_layer.addLayer(substrate_layer)
    return multi_layer


def get_simulation():
    """
    Create and return GISAXS simulation with beam and detector defined
    """
    simulation = Simulation()
    simulation.setDetectorParameters(100, phi_min*degree, phi_max*degree, 100, alpha_min*degree, alpha_max*degree)
    simulation.setBeamParameters(1.0*angstrom, 0.2*degree, 0.0*degree)
    return simulation


def run_simulation():
    """
    Run simulation and plot results
    """
    sample = get_sample()
    simulation = get_simulation()
    simulation.setSample(sample)
    simulation.runSimulation()
    result = simulation.getIntensityData().getArray() + 1  # for log scale

    # showing the result
    im = pylab.imshow(numpy.rot90(result, 1), norm=matplotlib.colors.LogNorm(),
                      extent=[phi_min, phi_max, alpha_min, alpha_max])
    cb = pylab.colorbar(im)
    cb.set_label(r'Intensity (arb. u.)', size=16)
    pylab.xlabel(r'$\phi_f (^{\circ})$', fontsize=16)
    pylab.ylabel(r'$\alpha_f (^{\circ})$', fontsize=16)
    pylab.show()


if __name__ == '__main__':
    run_simulation()


