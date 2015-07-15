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
#include "IMinimizer.pypp.h"

namespace bp = boost::python;

struct IMinimizer_wrapper : IMinimizer, bp::wrapper< IMinimizer > {

    IMinimizer_wrapper( )
    : IMinimizer( )
      , bp::wrapper< IMinimizer >(){
        // null constructor
    
    }

    virtual void clear(  ) {
        if( bp::override func_clear = this->get_override( "clear" ) )
            func_clear(  );
        else{
            this->IMinimizer::clear(  );
        }
    }
    
    void default_clear(  ) {
        IMinimizer::clear( );
    }

    virtual double getErrorOfVariable( ::std::size_t arg0 ) const  {
        if( bp::override func_getErrorOfVariable = this->get_override( "getErrorOfVariable" ) )
            return func_getErrorOfVariable( arg0 );
        else{
            return this->IMinimizer::getErrorOfVariable( arg0 );
        }
    }
    
    double default_getErrorOfVariable( ::std::size_t arg0 ) const  {
        return IMinimizer::getErrorOfVariable( arg0 );
    }

    virtual ::std::vector< double > getErrorOfVariables(  ) const  {
        if( bp::override func_getErrorOfVariables = this->get_override( "getErrorOfVariables" ) )
            return func_getErrorOfVariables(  );
        else{
            return this->IMinimizer::getErrorOfVariables(  );
        }
    }
    
    ::std::vector< double > default_getErrorOfVariables(  ) const  {
        return IMinimizer::getErrorOfVariables( );
    }

    virtual double getMinValue(  ) const  {
        if( bp::override func_getMinValue = this->get_override( "getMinValue" ) )
            return func_getMinValue(  );
        else{
            return this->IMinimizer::getMinValue(  );
        }
    }
    
    double default_getMinValue(  ) const  {
        return IMinimizer::getMinValue( );
    }

    virtual ::std::size_t getNCalls(  ) const  {
        if( bp::override func_getNCalls = this->get_override( "getNCalls" ) )
            return func_getNCalls(  );
        else{
            return this->IMinimizer::getNCalls(  );
        }
    }
    
    ::std::size_t default_getNCalls(  ) const  {
        return IMinimizer::getNCalls( );
    }

    virtual ::std::size_t getNumberOfVariables(  ) const  {
        if( bp::override func_getNumberOfVariables = this->get_override( "getNumberOfVariables" ) )
            return func_getNumberOfVariables(  );
        else{
            return this->IMinimizer::getNumberOfVariables(  );
        }
    }
    
    ::std::size_t default_getNumberOfVariables(  ) const  {
        return IMinimizer::getNumberOfVariables( );
    }

    virtual double getValueOfVariableAtMinimum( ::std::size_t arg0 ) const  {
        if( bp::override func_getValueOfVariableAtMinimum = this->get_override( "getValueOfVariableAtMinimum" ) )
            return func_getValueOfVariableAtMinimum( arg0 );
        else{
            return this->IMinimizer::getValueOfVariableAtMinimum( arg0 );
        }
    }
    
    double default_getValueOfVariableAtMinimum( ::std::size_t arg0 ) const  {
        return IMinimizer::getValueOfVariableAtMinimum( arg0 );
    }

    virtual ::std::vector< double > getValueOfVariablesAtMinimum(  ) const  {
        if( bp::override func_getValueOfVariablesAtMinimum = this->get_override( "getValueOfVariablesAtMinimum" ) )
            return func_getValueOfVariablesAtMinimum(  );
        else{
            return this->IMinimizer::getValueOfVariablesAtMinimum(  );
        }
    }
    
    ::std::vector< double > default_getValueOfVariablesAtMinimum(  ) const  {
        return IMinimizer::getValueOfVariablesAtMinimum( );
    }

    virtual bool isGradientBasedAgorithm(  ) {
        if( bp::override func_isGradientBasedAgorithm = this->get_override( "isGradientBasedAgorithm" ) )
            return func_isGradientBasedAgorithm(  );
        else{
            return this->IMinimizer::isGradientBasedAgorithm(  );
        }
    }
    
    bool default_isGradientBasedAgorithm(  ) {
        return IMinimizer::isGradientBasedAgorithm( );
    }

    virtual void minimize(  ){
        bp::override func_minimize = this->get_override( "minimize" );
        func_minimize(  );
    }

    virtual void printResults(  ) const  {
        if( bp::override func_printResults = this->get_override( "printResults" ) )
            func_printResults(  );
        else{
            this->IMinimizer::printResults(  );
        }
    }
    
    void default_printResults(  ) const  {
        IMinimizer::printResults( );
    }

    virtual void setOptionString( ::std::string const & arg0 ) {
        if( bp::override func_setOptionString = this->get_override( "setOptionString" ) )
            func_setOptionString( arg0 );
        else{
            this->IMinimizer::setOptionString( arg0 );
        }
    }
    
    void default_setOptionString( ::std::string const & arg0 ) {
        IMinimizer::setOptionString( arg0 );
    }

    virtual void setOptions( ::MinimizerOptions const & arg0 ) {
        if( bp::override func_setOptions = this->get_override( "setOptions" ) )
            func_setOptions( boost::ref(arg0) );
        else{
            this->IMinimizer::setOptions( boost::ref(arg0) );
        }
    }
    
    void default_setOptions( ::MinimizerOptions const & arg0 ) {
        IMinimizer::setOptions( boost::ref(arg0) );
    }

    virtual void setParameters( ::FitSuiteParameters const & arg0 ) {
        if( bp::override func_setParameters = this->get_override( "setParameters" ) )
            func_setParameters( boost::ref(arg0) );
        else{
            this->IMinimizer::setParameters( boost::ref(arg0) );
        }
    }
    
    void default_setParameters( ::FitSuiteParameters const & arg0 ) {
        IMinimizer::setParameters( boost::ref(arg0) );
    }

    virtual ::std::string getAlgorithmName(  ) const  {
            if( bp::override func_getAlgorithmName = this->get_override( "getAlgorithmName" ) )
                return boost::python::call<std::string>(func_getAlgorithmName(  ));
            else{
                return this->IMinimizer::getAlgorithmName(  );
            }
        }
    
        ::std::string default_getAlgorithmName(  ) const  {
            return IMinimizer::getAlgorithmName( );
        }

    virtual ::std::string getMinimizerName(  ) const  {
            if( bp::override func_getMinimizerName = this->get_override( "getMinimizerName" ) )
                return boost::python::call<std::string>(func_getMinimizerName(  ));
            else{
                return this->IMinimizer::getMinimizerName(  );
            }
        }
    
        ::std::string default_getMinimizerName(  ) const  {
            return IMinimizer::getMinimizerName( );
        }

};

void register_IMinimizer_class(){

    { //::IMinimizer
        typedef bp::class_< IMinimizer_wrapper, boost::noncopyable > IMinimizer_exposer_t;
        IMinimizer_exposer_t IMinimizer_exposer = IMinimizer_exposer_t( "IMinimizer", "Common interface for all kind minimizer'.", bp::init< >("signature of gradient to minimize with access to single data element residuals.") );
        bp::scope IMinimizer_scope( IMinimizer_exposer );
        { //::IMinimizer::clear
        
            typedef void ( ::IMinimizer::*clear_function_type)(  ) ;
            typedef void ( IMinimizer_wrapper::*default_clear_function_type)(  ) ;
            
            IMinimizer_exposer.def( 
                "clear"
                , clear_function_type(&::IMinimizer::clear)
                , default_clear_function_type(&IMinimizer_wrapper::default_clear) );
        
        }
        { //::IMinimizer::getErrorOfVariable
        
            typedef double ( ::IMinimizer::*getErrorOfVariable_function_type)( ::std::size_t ) const;
            typedef double ( IMinimizer_wrapper::*default_getErrorOfVariable_function_type)( ::std::size_t ) const;
            
            IMinimizer_exposer.def( 
                "getErrorOfVariable"
                , getErrorOfVariable_function_type(&::IMinimizer::getErrorOfVariable)
                , default_getErrorOfVariable_function_type(&IMinimizer_wrapper::default_getErrorOfVariable)
                , ( bp::arg("arg0") ) );
        
        }
        { //::IMinimizer::getErrorOfVariables
        
            typedef ::std::vector< double > ( ::IMinimizer::*getErrorOfVariables_function_type)(  ) const;
            typedef ::std::vector< double > ( IMinimizer_wrapper::*default_getErrorOfVariables_function_type)(  ) const;
            
            IMinimizer_exposer.def( 
                "getErrorOfVariables"
                , getErrorOfVariables_function_type(&::IMinimizer::getErrorOfVariables)
                , default_getErrorOfVariables_function_type(&IMinimizer_wrapper::default_getErrorOfVariables) );
        
        }
        { //::IMinimizer::getMinValue
        
            typedef double ( ::IMinimizer::*getMinValue_function_type)(  ) const;
            typedef double ( IMinimizer_wrapper::*default_getMinValue_function_type)(  ) const;
            
            IMinimizer_exposer.def( 
                "getMinValue"
                , getMinValue_function_type(&::IMinimizer::getMinValue)
                , default_getMinValue_function_type(&IMinimizer_wrapper::default_getMinValue) );
        
        }
        { //::IMinimizer::getNCalls
        
            typedef ::std::size_t ( ::IMinimizer::*getNCalls_function_type)(  ) const;
            typedef ::std::size_t ( IMinimizer_wrapper::*default_getNCalls_function_type)(  ) const;
            
            IMinimizer_exposer.def( 
                "getNCalls"
                , getNCalls_function_type(&::IMinimizer::getNCalls)
                , default_getNCalls_function_type(&IMinimizer_wrapper::default_getNCalls) );
        
        }
        { //::IMinimizer::getNumberOfVariables
        
            typedef ::std::size_t ( ::IMinimizer::*getNumberOfVariables_function_type)(  ) const;
            typedef ::std::size_t ( IMinimizer_wrapper::*default_getNumberOfVariables_function_type)(  ) const;
            
            IMinimizer_exposer.def( 
                "getNumberOfVariables"
                , getNumberOfVariables_function_type(&::IMinimizer::getNumberOfVariables)
                , default_getNumberOfVariables_function_type(&IMinimizer_wrapper::default_getNumberOfVariables) );
        
        }
        { //::IMinimizer::getOptions
        
            typedef ::MinimizerOptions & ( ::IMinimizer::*getOptions_function_type)(  ) ;
            
            IMinimizer_exposer.def( 
                "getOptions"
                , getOptions_function_type(&::IMinimizer::getOptions)
                , bp::return_internal_reference< >() );
        
        }
        { //::IMinimizer::getOptions
        
            typedef ::MinimizerOptions const & ( ::IMinimizer::*getOptions_function_type)(  ) const;
            
            IMinimizer_exposer.def( 
                "getOptions"
                , getOptions_function_type(&::IMinimizer::getOptions)
                , bp::return_internal_reference< >() );
        
        }
        { //::IMinimizer::getValueOfVariableAtMinimum
        
            typedef double ( ::IMinimizer::*getValueOfVariableAtMinimum_function_type)( ::std::size_t ) const;
            typedef double ( IMinimizer_wrapper::*default_getValueOfVariableAtMinimum_function_type)( ::std::size_t ) const;
            
            IMinimizer_exposer.def( 
                "getValueOfVariableAtMinimum"
                , getValueOfVariableAtMinimum_function_type(&::IMinimizer::getValueOfVariableAtMinimum)
                , default_getValueOfVariableAtMinimum_function_type(&IMinimizer_wrapper::default_getValueOfVariableAtMinimum)
                , ( bp::arg("arg0") ) );
        
        }
        { //::IMinimizer::getValueOfVariablesAtMinimum
        
            typedef ::std::vector< double > ( ::IMinimizer::*getValueOfVariablesAtMinimum_function_type)(  ) const;
            typedef ::std::vector< double > ( IMinimizer_wrapper::*default_getValueOfVariablesAtMinimum_function_type)(  ) const;
            
            IMinimizer_exposer.def( 
                "getValueOfVariablesAtMinimum"
                , getValueOfVariablesAtMinimum_function_type(&::IMinimizer::getValueOfVariablesAtMinimum)
                , default_getValueOfVariablesAtMinimum_function_type(&IMinimizer_wrapper::default_getValueOfVariablesAtMinimum) );
        
        }
        { //::IMinimizer::isGradientBasedAgorithm
        
            typedef bool ( ::IMinimizer::*isGradientBasedAgorithm_function_type)(  ) ;
            typedef bool ( IMinimizer_wrapper::*default_isGradientBasedAgorithm_function_type)(  ) ;
            
            IMinimizer_exposer.def( 
                "isGradientBasedAgorithm"
                , isGradientBasedAgorithm_function_type(&::IMinimizer::isGradientBasedAgorithm)
                , default_isGradientBasedAgorithm_function_type(&IMinimizer_wrapper::default_isGradientBasedAgorithm) );
        
        }
        { //::IMinimizer::minimize
        
            typedef void ( ::IMinimizer::*minimize_function_type)(  ) ;
            
            IMinimizer_exposer.def( 
                "minimize"
                , bp::pure_virtual( minimize_function_type(&::IMinimizer::minimize) )
                , "run minimization." );
        
        }
        { //::IMinimizer::printResults
        
            typedef void ( ::IMinimizer::*printResults_function_type)(  ) const;
            typedef void ( IMinimizer_wrapper::*default_printResults_function_type)(  ) const;
            
            IMinimizer_exposer.def( 
                "printResults"
                , printResults_function_type(&::IMinimizer::printResults)
                , default_printResults_function_type(&IMinimizer_wrapper::default_printResults) );
        
        }
        { //::IMinimizer::setOptionString
        
            typedef void ( ::IMinimizer::*setOptionString_function_type)( ::std::string const & ) ;
            typedef void ( IMinimizer_wrapper::*default_setOptionString_function_type)( ::std::string const & ) ;
            
            IMinimizer_exposer.def( 
                "setOptionString"
                , setOptionString_function_type(&::IMinimizer::setOptionString)
                , default_setOptionString_function_type(&IMinimizer_wrapper::default_setOptionString)
                , ( bp::arg("arg0") ) );
        
        }
        { //::IMinimizer::setOptions
        
            typedef void ( ::IMinimizer::*setOptions_function_type)( ::MinimizerOptions const & ) ;
            typedef void ( IMinimizer_wrapper::*default_setOptions_function_type)( ::MinimizerOptions const & ) ;
            
            IMinimizer_exposer.def( 
                "setOptions"
                , setOptions_function_type(&::IMinimizer::setOptions)
                , default_setOptions_function_type(&IMinimizer_wrapper::default_setOptions)
                , ( bp::arg("arg0") ) );
        
        }
        { //::IMinimizer::setParameters
        
            typedef void ( ::IMinimizer::*setParameters_function_type)( ::FitSuiteParameters const & ) ;
            typedef void ( IMinimizer_wrapper::*default_setParameters_function_type)( ::FitSuiteParameters const & ) ;
            
            IMinimizer_exposer.def( 
                "setParameters"
                , setParameters_function_type(&::IMinimizer::setParameters)
                , default_setParameters_function_type(&IMinimizer_wrapper::default_setParameters)
                , ( bp::arg("arg0") ) );
        
        }
        IMinimizer_exposer.def(
                        "getAlgorithmName"
                        , (::std::string ( ::IMinimizer::*)(  ) const)(&::IMinimizer::getAlgorithmName)
                        , (::std::string ( IMinimizer_wrapper::*)(  ) const)(&IMinimizer_wrapper::default_getAlgorithmName) );
        IMinimizer_exposer.def(
                        "getMinimizerName"
                        , (::std::string ( ::IMinimizer::*)(  ) const)(&::IMinimizer::getMinimizerName)
                        , (::std::string ( IMinimizer_wrapper::*)(  ) const)(&IMinimizer_wrapper::default_getMinimizerName) );
    }

}