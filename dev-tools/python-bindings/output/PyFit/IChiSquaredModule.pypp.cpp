// This file has been generated by Py++.

// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Automatically generated boost::python code for BornAgain Python bindings
//! @brief     Automatically generated boost::python code for BornAgain Python bindings
//!
//! @homepage  http://bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Juelich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "PythonFitList.h"
#include "IChiSquaredModule.pypp.h"

namespace bp = boost::python;

struct IChiSquaredModule_wrapper : IChiSquaredModule, bp::wrapper< IChiSquaredModule > {

    IChiSquaredModule_wrapper( )
    : IChiSquaredModule( )
      , bp::wrapper< IChiSquaredModule >(){
        // null constructor
    m_pyobj = 0;
    }

    virtual double calculateChiSquared(  ){
        bp::override func_calculateChiSquared = this->get_override( "calculateChiSquared" );
        return func_calculateChiSquared(  );
    }

    virtual ::IChiSquaredModule * clone(  ) const {
        bp::override func_clone = this->get_override( "clone" );
        return func_clone(  );
    }

    virtual ::OutputData< double > * createChi2DifferenceMap(  ) const {
        bp::override func_createChi2DifferenceMap = this->get_override( "createChi2DifferenceMap" );
        return func_createChi2DifferenceMap(  );
    }

    virtual ::IFittingDataSelector const * getFittingDataSelector(  ) const  {
        if( bp::override func_getFittingDataSelector = this->get_override( "getFittingDataSelector" ) )
            return func_getFittingDataSelector(  );
        else{
            return this->IChiSquaredModule::getFittingDataSelector(  );
        }
    }
    
    ::IFittingDataSelector const * default_getFittingDataSelector(  ) const  {
        return IChiSquaredModule::getFittingDataSelector( );
    }

    virtual ::IIntensityFunction const * getIntensityFunction(  ) const  {
        if( bp::override func_getIntensityFunction = this->get_override( "getIntensityFunction" ) )
            return func_getIntensityFunction(  );
        else{
            return this->IChiSquaredModule::getIntensityFunction(  );
        }
    }
    
    ::IIntensityFunction const * default_getIntensityFunction(  ) const  {
        return IChiSquaredModule::getIntensityFunction( );
    }

    virtual ::IIntensityNormalizer const * getIntensityNormalizer(  ) const  {
        if( bp::override func_getIntensityNormalizer = this->get_override( "getIntensityNormalizer" ) )
            return func_getIntensityNormalizer(  );
        else{
            return this->IChiSquaredModule::getIntensityNormalizer(  );
        }
    }
    
    ::IIntensityNormalizer const * default_getIntensityNormalizer(  ) const  {
        return IChiSquaredModule::getIntensityNormalizer( );
    }

    virtual ::IIntensityNormalizer * getIntensityNormalizer(  ) {
        if( bp::override func_getIntensityNormalizer = this->get_override( "getIntensityNormalizer" ) )
            return func_getIntensityNormalizer(  );
        else{
            return this->IChiSquaredModule::getIntensityNormalizer(  );
        }
    }
    
    ::IIntensityNormalizer * default_getIntensityNormalizer(  ) {
        return IChiSquaredModule::getIntensityNormalizer( );
    }

    virtual double getResidualValue( ::std::size_t arg0 ) const  {
        if( bp::override func_getResidualValue = this->get_override( "getResidualValue" ) )
            return func_getResidualValue( arg0 );
        else{
            return this->IChiSquaredModule::getResidualValue( arg0 );
        }
    }
    
    double default_getResidualValue( ::std::size_t arg0 ) const  {
        return IChiSquaredModule::getResidualValue( arg0 );
    }

    virtual void setFittingDataSelector( ::IFittingDataSelector const & selector ) {
        if( bp::override func_setFittingDataSelector = this->get_override( "setFittingDataSelector" ) )
            func_setFittingDataSelector( boost::ref(selector) );
        else{
            this->IChiSquaredModule::setFittingDataSelector( boost::ref(selector) );
        }
    }
    
    void default_setFittingDataSelector( ::IFittingDataSelector const & selector ) {
        IChiSquaredModule::setFittingDataSelector( boost::ref(selector) );
    }

    virtual void setIntensityFunction( ::IIntensityFunction const & intensity_function ) {
        if( bp::override func_setIntensityFunction = this->get_override( "setIntensityFunction" ) )
            func_setIntensityFunction( boost::ref(intensity_function) );
        else{
            this->IChiSquaredModule::setIntensityFunction( boost::ref(intensity_function) );
        }
    }
    
    void default_setIntensityFunction( ::IIntensityFunction const & intensity_function ) {
        IChiSquaredModule::setIntensityFunction( boost::ref(intensity_function) );
    }

    virtual void setIntensityNormalizer( ::IIntensityNormalizer const & data_normalizer ) {
        if( bp::override func_setIntensityNormalizer = this->get_override( "setIntensityNormalizer" ) )
            func_setIntensityNormalizer( boost::ref(data_normalizer) );
        else{
            this->IChiSquaredModule::setIntensityNormalizer( boost::ref(data_normalizer) );
        }
    }
    
    void default_setIntensityNormalizer( ::IIntensityNormalizer const & data_normalizer ) {
        IChiSquaredModule::setIntensityNormalizer( boost::ref(data_normalizer) );
    }

    PyObject* m_pyobj;

};

void register_IChiSquaredModule_class(){

    { //::IChiSquaredModule
        typedef bp::class_< IChiSquaredModule_wrapper, std::auto_ptr< IChiSquaredModule_wrapper >, boost::noncopyable > IChiSquaredModule_exposer_t;
        IChiSquaredModule_exposer_t IChiSquaredModule_exposer = IChiSquaredModule_exposer_t( "IChiSquaredModule", "Interface for ChiSquaredModule, ChiSquaredFrequency for chi2 calculations.", bp::init< >() );
        bp::scope IChiSquaredModule_scope( IChiSquaredModule_exposer );
        { //::IChiSquaredModule::calculateChiSquared
        
            typedef double ( ::IChiSquaredModule::*calculateChiSquared_function_type)(  ) ;
            
            IChiSquaredModule_exposer.def( 
                "calculateChiSquared"
                , bp::pure_virtual( calculateChiSquared_function_type(&::IChiSquaredModule::calculateChiSquared) )
                , "Returns chi squared value." );
        
        }
        { //::IChiSquaredModule::clone
        
            typedef ::IChiSquaredModule * ( ::IChiSquaredModule::*clone_function_type)(  ) const;
            
            IChiSquaredModule_exposer.def( 
                "clone"
                , bp::pure_virtual( clone_function_type(&::IChiSquaredModule::clone) )
                , bp::return_value_policy< bp::manage_new_object >()
                , "clone method." );
        
        }
        { //::IChiSquaredModule::createChi2DifferenceMap
        
            typedef ::OutputData<double> * ( ::IChiSquaredModule::*createChi2DifferenceMap_function_type)(  ) const;
            
            IChiSquaredModule_exposer.def( 
                "createChi2DifferenceMap"
                , bp::pure_virtual( createChi2DifferenceMap_function_type(&::IChiSquaredModule::createChi2DifferenceMap) )
                , bp::return_value_policy< bp::manage_new_object >()
                , "Returns output data which contains chi^2 values." );
        
        }
        { //::IChiSquaredModule::getFittingDataSelector
        
            typedef ::IFittingDataSelector const * ( ::IChiSquaredModule::*getFittingDataSelector_function_type)(  ) const;
            typedef ::IFittingDataSelector const * ( IChiSquaredModule_wrapper::*default_getFittingDataSelector_function_type)(  ) const;
            
            IChiSquaredModule_exposer.def( 
                "getFittingDataSelector"
                , getFittingDataSelector_function_type(&::IChiSquaredModule::getFittingDataSelector)
                , default_getFittingDataSelector_function_type(&IChiSquaredModule_wrapper::default_getFittingDataSelector)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IChiSquaredModule::getIntensityFunction
        
            typedef ::IIntensityFunction const * ( ::IChiSquaredModule::*getIntensityFunction_function_type)(  ) const;
            typedef ::IIntensityFunction const * ( IChiSquaredModule_wrapper::*default_getIntensityFunction_function_type)(  ) const;
            
            IChiSquaredModule_exposer.def( 
                "getIntensityFunction"
                , getIntensityFunction_function_type(&::IChiSquaredModule::getIntensityFunction)
                , default_getIntensityFunction_function_type(&IChiSquaredModule_wrapper::default_getIntensityFunction)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IChiSquaredModule::getIntensityNormalizer
        
            typedef ::IIntensityNormalizer const * ( ::IChiSquaredModule::*getIntensityNormalizer_function_type)(  ) const;
            typedef ::IIntensityNormalizer const * ( IChiSquaredModule_wrapper::*default_getIntensityNormalizer_function_type)(  ) const;
            
            IChiSquaredModule_exposer.def( 
                "getIntensityNormalizer"
                , getIntensityNormalizer_function_type(&::IChiSquaredModule::getIntensityNormalizer)
                , default_getIntensityNormalizer_function_type(&IChiSquaredModule_wrapper::default_getIntensityNormalizer)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IChiSquaredModule::getIntensityNormalizer
        
            typedef ::IIntensityNormalizer * ( ::IChiSquaredModule::*getIntensityNormalizer_function_type)(  ) ;
            typedef ::IIntensityNormalizer * ( IChiSquaredModule_wrapper::*default_getIntensityNormalizer_function_type)(  ) ;
            
            IChiSquaredModule_exposer.def( 
                "getIntensityNormalizer"
                , getIntensityNormalizer_function_type(&::IChiSquaredModule::getIntensityNormalizer)
                , default_getIntensityNormalizer_function_type(&IChiSquaredModule_wrapper::default_getIntensityNormalizer)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IChiSquaredModule::getRealData
        
            typedef ::OutputData< double > const * ( ::IChiSquaredModule::*getRealData_function_type)(  ) const;
            
            IChiSquaredModule_exposer.def( 
                "getRealData"
                , getRealData_function_type( &::IChiSquaredModule::getRealData )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "Returns real data." );
        
        }
        { //::IChiSquaredModule::getResidualValue
        
            typedef double ( ::IChiSquaredModule::*getResidualValue_function_type)( ::std::size_t ) const;
            typedef double ( IChiSquaredModule_wrapper::*default_getResidualValue_function_type)( ::std::size_t ) const;
            
            IChiSquaredModule_exposer.def( 
                "getResidualValue"
                , getResidualValue_function_type(&::IChiSquaredModule::getResidualValue)
                , default_getResidualValue_function_type(&IChiSquaredModule_wrapper::default_getResidualValue)
                , ( bp::arg("arg0") ) );
        
        }
        { //::IChiSquaredModule::getSimulationData
        
            typedef ::OutputData< double > const * ( ::IChiSquaredModule::*getSimulationData_function_type)(  ) const;
            
            IChiSquaredModule_exposer.def( 
                "getSimulationData"
                , getSimulationData_function_type( &::IChiSquaredModule::getSimulationData )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "Returns simulated data." );
        
        }
        { //::IChiSquaredModule::getSquaredFunction
        
            typedef ::ISquaredFunction const * ( ::IChiSquaredModule::*getSquaredFunction_function_type)(  ) const;
            
            IChiSquaredModule_exposer.def( 
                "getSquaredFunction"
                , getSquaredFunction_function_type( &::IChiSquaredModule::getSquaredFunction )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "Returns squared function." );
        
        }
        { //::IChiSquaredModule::setChiSquaredFunction
        
            typedef void ( ::IChiSquaredModule::*setChiSquaredFunction_function_type)( ::ISquaredFunction const & ) ;
            
            IChiSquaredModule_exposer.def( 
                "setChiSquaredFunction"
                , setChiSquaredFunction_function_type( &::IChiSquaredModule::setChiSquaredFunction )
                , ( bp::arg("squared_function") )
                , "Sets squared function." );
        
        }
        { //::IChiSquaredModule::setFittingDataSelector
        
            typedef void ( ::IChiSquaredModule::*setFittingDataSelector_function_type)( ::IFittingDataSelector const & ) ;
            typedef void ( IChiSquaredModule_wrapper::*default_setFittingDataSelector_function_type)( ::IFittingDataSelector const & ) ;
            
            IChiSquaredModule_exposer.def( 
                "setFittingDataSelector"
                , setFittingDataSelector_function_type(&::IChiSquaredModule::setFittingDataSelector)
                , default_setFittingDataSelector_function_type(&IChiSquaredModule_wrapper::default_setFittingDataSelector)
                , ( bp::arg("selector") ) );
        
        }
        { //::IChiSquaredModule::setIntensityFunction
        
            typedef void ( ::IChiSquaredModule::*setIntensityFunction_function_type)( ::IIntensityFunction const & ) ;
            typedef void ( IChiSquaredModule_wrapper::*default_setIntensityFunction_function_type)( ::IIntensityFunction const & ) ;
            
            IChiSquaredModule_exposer.def( 
                "setIntensityFunction"
                , setIntensityFunction_function_type(&::IChiSquaredModule::setIntensityFunction)
                , default_setIntensityFunction_function_type(&IChiSquaredModule_wrapper::default_setIntensityFunction)
                , ( bp::arg("intensity_function") ) );
        
        }
        { //::IChiSquaredModule::setIntensityNormalizer
        
            typedef void ( ::IChiSquaredModule::*setIntensityNormalizer_function_type)( ::IIntensityNormalizer const & ) ;
            typedef void ( IChiSquaredModule_wrapper::*default_setIntensityNormalizer_function_type)( ::IIntensityNormalizer const & ) ;
            
            IChiSquaredModule_exposer.def( 
                "setIntensityNormalizer"
                , setIntensityNormalizer_function_type(&::IChiSquaredModule::setIntensityNormalizer)
                , default_setIntensityNormalizer_function_type(&IChiSquaredModule_wrapper::default_setIntensityNormalizer)
                , ( bp::arg("data_normalizer") ) );
        
        }
        { //::IChiSquaredModule::setNdegreeOfFreedom
        
            typedef void ( ::IChiSquaredModule::*setNdegreeOfFreedom_function_type)( int ) ;
            
            IChiSquaredModule_exposer.def( 
                "setNdegreeOfFreedom"
                , setNdegreeOfFreedom_function_type( &::IChiSquaredModule::setNdegreeOfFreedom )
                , ( bp::arg("ndegree_of_freedom") )
                , "Sets number of degree of freedom." );
        
        }
        { //::IChiSquaredModule::setRealAndSimulatedData
        
            typedef void ( ::IChiSquaredModule::*setRealAndSimulatedData_function_type)( ::OutputData< double > const &,::OutputData< double > const & ) ;
            
            IChiSquaredModule_exposer.def( 
                "setRealAndSimulatedData"
                , setRealAndSimulatedData_function_type( &::IChiSquaredModule::setRealAndSimulatedData )
                , ( bp::arg("real_data"), bp::arg("simulation_data") )
                , "Sets real and simulated data pair." );
        
        }
    }

}