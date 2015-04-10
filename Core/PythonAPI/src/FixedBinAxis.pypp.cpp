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
#include "PythonCoreList.h"
#include "FixedBinAxis.pypp.h"

namespace bp = boost::python;

struct FixedBinAxis_wrapper : FixedBinAxis, bp::wrapper< FixedBinAxis > {

    FixedBinAxis_wrapper(::std::string const & name, ::size_t nbins, double start, double end )
    : FixedBinAxis( name, nbins, start, end )
      , bp::wrapper< FixedBinAxis >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::FixedBinAxis * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->FixedBinAxis::clone(  );
        }
    }
    
    ::FixedBinAxis * default_clone(  ) const  {
        return FixedBinAxis::clone( );
    }

    virtual ::FixedBinAxis * createClippedAxis( double left, double right ) const  {
        if( bp::override func_createClippedAxis = this->get_override( "createClippedAxis" ) )
            return func_createClippedAxis( left, right );
        else{
            return this->FixedBinAxis::createClippedAxis( left, right );
        }
    }
    
    ::FixedBinAxis * default_createClippedAxis( double left, double right ) const  {
        return FixedBinAxis::createClippedAxis( left, right );
    }

    virtual ::size_t findClosestIndex( double value ) const  {
        if( bp::override func_findClosestIndex = this->get_override( "findClosestIndex" ) )
            return func_findClosestIndex( value );
        else{
            return this->FixedBinAxis::findClosestIndex( value );
        }
    }
    
    ::size_t default_findClosestIndex( double value ) const  {
        return FixedBinAxis::findClosestIndex( value );
    }

    virtual ::Bin1D getBin( ::size_t index ) const  {
        if( bp::override func_getBin = this->get_override( "getBin" ) )
            return func_getBin( index );
        else{
            return this->FixedBinAxis::getBin( index );
        }
    }
    
    ::Bin1D default_getBin( ::size_t index ) const  {
        return FixedBinAxis::getBin( index );
    }

    virtual ::std::vector< double > getBinBoundaries(  ) const  {
        if( bp::override func_getBinBoundaries = this->get_override( "getBinBoundaries" ) )
            return func_getBinBoundaries(  );
        else{
            return this->FixedBinAxis::getBinBoundaries(  );
        }
    }
    
    ::std::vector< double > default_getBinBoundaries(  ) const  {
        return FixedBinAxis::getBinBoundaries( );
    }

    virtual ::std::vector< double > getBinCenters(  ) const  {
        if( bp::override func_getBinCenters = this->get_override( "getBinCenters" ) )
            return func_getBinCenters(  );
        else{
            return this->FixedBinAxis::getBinCenters(  );
        }
    }
    
    ::std::vector< double > default_getBinCenters(  ) const  {
        return FixedBinAxis::getBinCenters( );
    }

    virtual double getMax(  ) const  {
        if( bp::override func_getMax = this->get_override( "getMax" ) )
            return func_getMax(  );
        else{
            return this->FixedBinAxis::getMax(  );
        }
    }
    
    double default_getMax(  ) const  {
        return FixedBinAxis::getMax( );
    }

    virtual double getMin(  ) const  {
        if( bp::override func_getMin = this->get_override( "getMin" ) )
            return func_getMin(  );
        else{
            return this->FixedBinAxis::getMin(  );
        }
    }
    
    double default_getMin(  ) const  {
        return FixedBinAxis::getMin( );
    }

    virtual ::size_t getSize(  ) const  {
        if( bp::override func_getSize = this->get_override( "getSize" ) )
            return func_getSize(  );
        else{
            return this->FixedBinAxis::getSize(  );
        }
    }
    
    ::size_t default_getSize(  ) const  {
        return FixedBinAxis::getSize( );
    }

    virtual double operator[]( ::size_t index ) const  {
        if( bp::override func___getitem__ = this->get_override( "__getitem__" ) )
            return func___getitem__( index );
        else{
            return this->FixedBinAxis::operator[]( index );
        }
    }
    
    double default___getitem__( ::size_t index ) const  {
        return FixedBinAxis::operator[]( index );
    }

    virtual bool contains( double value ) const  {
        if( bp::override func_contains = this->get_override( "contains" ) )
            return func_contains( value );
        else{
            return this->IAxis::contains( value );
        }
    }
    
    bool default_contains( double value ) const  {
        return IAxis::contains( value );
    }

    virtual ::IAxis * createDoubleBinSize(  ) const  {
        if( bp::override func_createDoubleBinSize = this->get_override( "createDoubleBinSize" ) )
            return func_createDoubleBinSize(  );
        else{
            return this->IAxis::createDoubleBinSize(  );
        }
    }
    
    ::IAxis * default_createDoubleBinSize(  ) const  {
        return IAxis::createDoubleBinSize( );
    }

    PyObject* m_pyobj;

};

void register_FixedBinAxis_class(){

    { //::FixedBinAxis
        typedef bp::class_< FixedBinAxis_wrapper, bp::bases< IAxis >, std::auto_ptr< FixedBinAxis_wrapper >, boost::noncopyable > FixedBinAxis_exposer_t;
        FixedBinAxis_exposer_t FixedBinAxis_exposer = FixedBinAxis_exposer_t( "FixedBinAxis", bp::init< std::string const &, size_t, double, double >(( bp::arg("name"), bp::arg("nbins"), bp::arg("start"), bp::arg("end") )) );
        bp::scope FixedBinAxis_scope( FixedBinAxis_exposer );
        { //::FixedBinAxis::clone
        
            typedef ::FixedBinAxis * ( ::FixedBinAxis::*clone_function_type)(  ) const;
            typedef ::FixedBinAxis * ( FixedBinAxis_wrapper::*default_clone_function_type)(  ) const;
            
            FixedBinAxis_exposer.def( 
                "clone"
                , clone_function_type(&::FixedBinAxis::clone)
                , default_clone_function_type(&FixedBinAxis_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::FixedBinAxis::createClippedAxis
        
            typedef ::FixedBinAxis * ( ::FixedBinAxis::*createClippedAxis_function_type)( double,double ) const;
            typedef ::FixedBinAxis * ( FixedBinAxis_wrapper::*default_createClippedAxis_function_type)( double,double ) const;
            
            FixedBinAxis_exposer.def( 
                "createClippedAxis"
                , createClippedAxis_function_type(&::FixedBinAxis::createClippedAxis)
                , default_createClippedAxis_function_type(&FixedBinAxis_wrapper::default_createClippedAxis)
                , ( bp::arg("left"), bp::arg("right") )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::FixedBinAxis::findClosestIndex
        
            typedef ::size_t ( ::FixedBinAxis::*findClosestIndex_function_type)( double ) const;
            typedef ::size_t ( FixedBinAxis_wrapper::*default_findClosestIndex_function_type)( double ) const;
            
            FixedBinAxis_exposer.def( 
                "findClosestIndex"
                , findClosestIndex_function_type(&::FixedBinAxis::findClosestIndex)
                , default_findClosestIndex_function_type(&FixedBinAxis_wrapper::default_findClosestIndex)
                , ( bp::arg("value") ) );
        
        }
        { //::FixedBinAxis::getBin
        
            typedef ::Bin1D ( ::FixedBinAxis::*getBin_function_type)( ::size_t ) const;
            typedef ::Bin1D ( FixedBinAxis_wrapper::*default_getBin_function_type)( ::size_t ) const;
            
            FixedBinAxis_exposer.def( 
                "getBin"
                , getBin_function_type(&::FixedBinAxis::getBin)
                , default_getBin_function_type(&FixedBinAxis_wrapper::default_getBin)
                , ( bp::arg("index") ) );
        
        }
        { //::FixedBinAxis::getBinBoundaries
        
            typedef ::std::vector< double > ( ::FixedBinAxis::*getBinBoundaries_function_type)(  ) const;
            typedef ::std::vector< double > ( FixedBinAxis_wrapper::*default_getBinBoundaries_function_type)(  ) const;
            
            FixedBinAxis_exposer.def( 
                "getBinBoundaries"
                , getBinBoundaries_function_type(&::FixedBinAxis::getBinBoundaries)
                , default_getBinBoundaries_function_type(&FixedBinAxis_wrapper::default_getBinBoundaries) );
        
        }
        { //::FixedBinAxis::getBinCenters
        
            typedef ::std::vector< double > ( ::FixedBinAxis::*getBinCenters_function_type)(  ) const;
            typedef ::std::vector< double > ( FixedBinAxis_wrapper::*default_getBinCenters_function_type)(  ) const;
            
            FixedBinAxis_exposer.def( 
                "getBinCenters"
                , getBinCenters_function_type(&::FixedBinAxis::getBinCenters)
                , default_getBinCenters_function_type(&FixedBinAxis_wrapper::default_getBinCenters) );
        
        }
        { //::FixedBinAxis::getMax
        
            typedef double ( ::FixedBinAxis::*getMax_function_type)(  ) const;
            typedef double ( FixedBinAxis_wrapper::*default_getMax_function_type)(  ) const;
            
            FixedBinAxis_exposer.def( 
                "getMax"
                , getMax_function_type(&::FixedBinAxis::getMax)
                , default_getMax_function_type(&FixedBinAxis_wrapper::default_getMax) );
        
        }
        { //::FixedBinAxis::getMin
        
            typedef double ( ::FixedBinAxis::*getMin_function_type)(  ) const;
            typedef double ( FixedBinAxis_wrapper::*default_getMin_function_type)(  ) const;
            
            FixedBinAxis_exposer.def( 
                "getMin"
                , getMin_function_type(&::FixedBinAxis::getMin)
                , default_getMin_function_type(&FixedBinAxis_wrapper::default_getMin) );
        
        }
        { //::FixedBinAxis::getSize
        
            typedef ::size_t ( ::FixedBinAxis::*getSize_function_type)(  ) const;
            typedef ::size_t ( FixedBinAxis_wrapper::*default_getSize_function_type)(  ) const;
            
            FixedBinAxis_exposer.def( 
                "getSize"
                , getSize_function_type(&::FixedBinAxis::getSize)
                , default_getSize_function_type(&FixedBinAxis_wrapper::default_getSize) );
        
        }
        { //::FixedBinAxis::operator[]
        
            typedef double ( ::FixedBinAxis::*__getitem___function_type)( ::size_t ) const;
            typedef double ( FixedBinAxis_wrapper::*default___getitem___function_type)( ::size_t ) const;
            
            FixedBinAxis_exposer.def( 
                "__getitem__"
                , __getitem___function_type(&::FixedBinAxis::operator[])
                , default___getitem___function_type(&FixedBinAxis_wrapper::default___getitem__)
                , ( bp::arg("index") ) );
        
        }
        { //::IAxis::contains
        
            typedef bool ( ::IAxis::*contains_function_type)( double ) const;
            typedef bool ( FixedBinAxis_wrapper::*default_contains_function_type)( double ) const;
            
            FixedBinAxis_exposer.def( 
                "contains"
                , contains_function_type(&::IAxis::contains)
                , default_contains_function_type(&FixedBinAxis_wrapper::default_contains)
                , ( bp::arg("value") ) );
        
        }
        { //::IAxis::createDoubleBinSize
        
            typedef ::IAxis * ( ::IAxis::*createDoubleBinSize_function_type)(  ) const;
            typedef ::IAxis * ( FixedBinAxis_wrapper::*default_createDoubleBinSize_function_type)(  ) const;
            
            FixedBinAxis_exposer.def( 
                "createDoubleBinSize"
                , createDoubleBinSize_function_type(&::IAxis::createDoubleBinSize)
                , default_createDoubleBinSize_function_type(&FixedBinAxis_wrapper::default_createDoubleBinSize)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
    }

}
