// This file has been generated by Py++.

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "BasicVector3D.h"
#include "FormFactorCrystal.h"
#include "FormFactorCylinder.h"
#include "FormFactorDecoratorDebyeWaller.h"
#include "FormFactorFullSphere.h"
#include "FormFactorGauss.h"
#include "FormFactorLorentz.h"
#include "FormFactorPrism3.h"
#include "FormFactorBox.h"
#include "FormFactorPyramid.h"
#include "FormFactorSphereGaussianRadius.h"
#include "FTDistributions.h"
#include "HomogeneousMaterial.h"
#include "ICloneable.h"
#include "IClusteredParticles.h"
#include "ICompositeSample.h"
#include "IDecoration.h"
#include "IFormFactor.h"
#include "IFormFactorBorn.h"
#include "IFormFactorDecorator.h"
#include "IInterferenceFunction.h"
#include "InterferenceFunctionNone.h"
#include "InterferenceFunction1DParaCrystal.h"
#include "InterferenceFunction2DParaCrystal.h"
#include "InterferenceFunction2DLattice.h"
#include "IMaterial.h"
#include "IParameterized.h"
#include "ISample.h"
#include "ISampleBuilder.h"
#include "ISelectionRule.h"
#include "ISingleton.h"
#include "Lattice.h"
#include "Lattice2DIFParameters.h"
#include "LatticeBasis.h"
#include "Layer.h"
#include "LayerDecorator.h"
#include "LayerRoughness.h"
#include "MaterialManager.h"
#include "MesoCrystal.h"
#include "MultiLayer.h"
#include "Particle.h"
#include "Crystal.h"
#include "ParticleDecoration.h"
#include "ParticleBuilder.h"
#include "OpticalFresnel.h"
#include "ParameterPool.h"
#include "PositionParticleInfo.h"
#include "ParticleInfo.h"
#include "DiffuseParticleInfo.h"
#include "PythonOutputData.h"
#include "PythonPlusplusHelper.h"
#include "RealParameterWrapper.h"
#include "Simulation.h"
#include "SimulationParameters.h"
#include "Transform3D.h"
#include "Units.h"
#include "Types.h"
#include "IFTDistribution2D.pypp.h"

namespace bp = boost::python;

struct IFTDistribution2D_wrapper : IFTDistribution2D, bp::wrapper< IFTDistribution2D > {

    IFTDistribution2D_wrapper(double omega_x, double omega_y )
    : IFTDistribution2D( omega_x, omega_y )
      , bp::wrapper< IFTDistribution2D >(){
        // constructor
    
    }

    virtual ::IFTDistribution2D * clone(  ) const {
        bp::override func_clone = this->get_override( "clone" );
        return func_clone(  );
    }

    virtual double evaluate( double qx, double qy ) const {
        bp::override func_evaluate = this->get_override( "evaluate" );
        return func_evaluate( qx, qy );
    }

    virtual void transformToStarBasis( double qX, double qY, double alpha, double a, double b, double & qa, double & qb ) const {
        bp::override func_transformToStarBasis = this->get_override( "transformToStarBasis" );
        func_transformToStarBasis( qX, qY, alpha, a, b, qa, qb );
    }

    virtual bool areParametersChanged(  ) {
        if( bp::override func_areParametersChanged = this->get_override( "areParametersChanged" ) )
            return func_areParametersChanged(  );
        else{
            return this->IParameterized::areParametersChanged(  );
        }
    }
    
    bool default_areParametersChanged(  ) {
        return IParameterized::areParametersChanged( );
    }

    virtual ::ParameterPool * createParameterTree(  ) const  {
        if( bp::override func_createParameterTree = this->get_override( "createParameterTree" ) )
            return func_createParameterTree(  );
        else{
            return this->IParameterized::createParameterTree(  );
        }
    }
    
    ::ParameterPool * default_createParameterTree(  ) const  {
        return IParameterized::createParameterTree( );
    }

    virtual void printParameters(  ) const  {
        if( bp::override func_printParameters = this->get_override( "printParameters" ) )
            func_printParameters(  );
        else{
            this->IParameterized::printParameters(  );
        }
    }
    
    void default_printParameters(  ) const  {
        IParameterized::printParameters( );
    }

    virtual void setParametersAreChanged(  ) {
        if( bp::override func_setParametersAreChanged = this->get_override( "setParametersAreChanged" ) )
            func_setParametersAreChanged(  );
        else{
            this->IParameterized::setParametersAreChanged(  );
        }
    }
    
    void default_setParametersAreChanged(  ) {
        IParameterized::setParametersAreChanged( );
    }

};

void register_IFTDistribution2D_class(){

    bp::class_< IFTDistribution2D_wrapper, bp::bases< IParameterized >, boost::noncopyable >( "IFTDistribution2D", bp::init< double, double >(( bp::arg("omega_x"), bp::arg("omega_y") )) )    
        .def( 
            "clone"
            , bp::pure_virtual( (::IFTDistribution2D * ( ::IFTDistribution2D::* )(  ) const)(&::IFTDistribution2D::clone) )
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "evaluate"
            , bp::pure_virtual( (double ( ::IFTDistribution2D::* )( double,double ) const)(&::IFTDistribution2D::evaluate) )
            , ( bp::arg("qx"), bp::arg("qy") ) )    
        .def( 
            "getDelta"
            , (double ( ::IFTDistribution2D::* )(  ) const)( &::IFTDistribution2D::getDelta ) )    
        .def( 
            "getGamma"
            , (double ( ::IFTDistribution2D::* )(  ) const)( &::IFTDistribution2D::getGamma ) )    
        .def( 
            "setGamma"
            , (void ( ::IFTDistribution2D::* )( double ) )( &::IFTDistribution2D::setGamma )
            , ( bp::arg("gamma") ) )    
        .def( 
            "transformToStarBasis"
            , bp::pure_virtual( (void ( ::IFTDistribution2D::* )( double,double,double,double,double,double &,double & ) const)(&::IFTDistribution2D::transformToStarBasis) )
            , ( bp::arg("qX"), bp::arg("qY"), bp::arg("alpha"), bp::arg("a"), bp::arg("b"), bp::arg("qa"), bp::arg("qb") ) )    
        .def( 
            "areParametersChanged"
            , (bool ( ::IParameterized::* )(  ) )(&::IParameterized::areParametersChanged)
            , (bool ( IFTDistribution2D_wrapper::* )(  ) )(&IFTDistribution2D_wrapper::default_areParametersChanged) )    
        .def( 
            "createParameterTree"
            , (::ParameterPool * ( ::IParameterized::* )(  ) const)(&::IParameterized::createParameterTree)
            , (::ParameterPool * ( IFTDistribution2D_wrapper::* )(  ) const)(&IFTDistribution2D_wrapper::default_createParameterTree)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "printParameters"
            , (void ( ::IParameterized::* )(  ) const)(&::IParameterized::printParameters)
            , (void ( IFTDistribution2D_wrapper::* )(  ) const)(&IFTDistribution2D_wrapper::default_printParameters) )    
        .def( 
            "setParametersAreChanged"
            , (void ( ::IParameterized::* )(  ) )(&::IParameterized::setParametersAreChanged)
            , (void ( IFTDistribution2D_wrapper::* )(  ) )(&IFTDistribution2D_wrapper::default_setParametersAreChanged) );

}
