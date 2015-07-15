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
#include "HomogeneousMaterial.pypp.h"

namespace bp = boost::python;

struct HomogeneousMaterial_wrapper : HomogeneousMaterial, bp::wrapper< HomogeneousMaterial > {

    HomogeneousMaterial_wrapper(HomogeneousMaterial const & arg )
    : HomogeneousMaterial( arg )
      , bp::wrapper< HomogeneousMaterial >(){
        // copy constructor
        m_pyobj = 0;
    }

    HomogeneousMaterial_wrapper(::std::string const & name, ::complex_t const & refractive_index )
    : HomogeneousMaterial( name, boost::ref(refractive_index) )
      , bp::wrapper< HomogeneousMaterial >(){
        // constructor
    m_pyobj = 0;
    }

    HomogeneousMaterial_wrapper(::std::string const & name, double refractive_index_delta, double refractive_index_beta )
    : HomogeneousMaterial( name, refractive_index_delta, refractive_index_beta )
      , bp::wrapper< HomogeneousMaterial >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::HomogeneousMaterial * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->HomogeneousMaterial::clone(  );
        }
    }
    
    ::HomogeneousMaterial * default_clone(  ) const  {
        return HomogeneousMaterial::clone( );
    }

    virtual ::IMaterial const * createTransformedMaterial( ::IRotation const & rotation ) const  {
        if( bp::override func_createTransformedMaterial = this->get_override( "createTransformedMaterial" ) )
            return func_createTransformedMaterial( boost::ref(rotation) );
        else{
            return this->HomogeneousMaterial::createTransformedMaterial( boost::ref(rotation) );
        }
    }
    
    ::IMaterial const * default_createTransformedMaterial( ::IRotation const & rotation ) const  {
        return HomogeneousMaterial::createTransformedMaterial( boost::ref(rotation) );
    }

    virtual ::complex_t getRefractiveIndex(  ) const  {
        if( bp::override func_getRefractiveIndex = this->get_override( "getRefractiveIndex" ) )
            return func_getRefractiveIndex(  );
        else{
            return this->HomogeneousMaterial::getRefractiveIndex(  );
        }
    }
    
    ::complex_t default_getRefractiveIndex(  ) const  {
        return HomogeneousMaterial::getRefractiveIndex( );
    }

    virtual bool isScalarMaterial(  ) const  {
        if( bp::override func_isScalarMaterial = this->get_override( "isScalarMaterial" ) )
            return func_isScalarMaterial(  );
        else{
            return this->IMaterial::isScalarMaterial(  );
        }
    }
    
    bool default_isScalarMaterial(  ) const  {
        return IMaterial::isScalarMaterial( );
    }

    PyObject* m_pyobj;

};

void register_HomogeneousMaterial_class(){

    { //::HomogeneousMaterial
        typedef bp::class_< HomogeneousMaterial_wrapper, bp::bases< IMaterial >, std::auto_ptr< HomogeneousMaterial_wrapper > > HomogeneousMaterial_exposer_t;
        HomogeneousMaterial_exposer_t HomogeneousMaterial_exposer = HomogeneousMaterial_exposer_t( "HomogeneousMaterial", "An homogeneous material with a refractive index.", bp::init< std::string const &, complex_t const & >(( bp::arg("name"), bp::arg("refractive_index") ), "Constructs a material with _name_ and _refractive_index_.") );
        bp::scope HomogeneousMaterial_scope( HomogeneousMaterial_exposer );
        HomogeneousMaterial_exposer.def( bp::init< std::string const &, double, double >(( bp::arg("name"), bp::arg("refractive_index_delta"), bp::arg("refractive_index_beta") ), "Constructs a material with _name_ and refractive_index parameters delta and beta (n = 1 - delta + i*beta). ") );
        { //::HomogeneousMaterial::clone
        
            typedef ::HomogeneousMaterial * ( ::HomogeneousMaterial::*clone_function_type)(  ) const;
            typedef ::HomogeneousMaterial * ( HomogeneousMaterial_wrapper::*default_clone_function_type)(  ) const;
            
            HomogeneousMaterial_exposer.def( 
                "clone"
                , clone_function_type(&::HomogeneousMaterial::clone)
                , default_clone_function_type(&HomogeneousMaterial_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::HomogeneousMaterial::createTransformedMaterial
        
            typedef ::IMaterial const * ( ::HomogeneousMaterial::*createTransformedMaterial_function_type)( ::IRotation const & ) const;
            typedef ::IMaterial const * ( HomogeneousMaterial_wrapper::*default_createTransformedMaterial_function_type)( ::IRotation const & ) const;
            
            HomogeneousMaterial_exposer.def( 
                "createTransformedMaterial"
                , createTransformedMaterial_function_type(&::HomogeneousMaterial::createTransformedMaterial)
                , default_createTransformedMaterial_function_type(&HomogeneousMaterial_wrapper::default_createTransformedMaterial)
                , ( bp::arg("rotation") )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::HomogeneousMaterial::getRefractiveIndex
        
            typedef ::complex_t ( ::HomogeneousMaterial::*getRefractiveIndex_function_type)(  ) const;
            typedef ::complex_t ( HomogeneousMaterial_wrapper::*default_getRefractiveIndex_function_type)(  ) const;
            
            HomogeneousMaterial_exposer.def( 
                "getRefractiveIndex"
                , getRefractiveIndex_function_type(&::HomogeneousMaterial::getRefractiveIndex)
                , default_getRefractiveIndex_function_type(&HomogeneousMaterial_wrapper::default_getRefractiveIndex) );
        
        }
        { //::HomogeneousMaterial::setRefractiveIndex
        
            typedef void ( ::HomogeneousMaterial::*setRefractiveIndex_function_type)( ::complex_t const & ) ;
            
            HomogeneousMaterial_exposer.def( 
                "setRefractiveIndex"
                , setRefractiveIndex_function_type( &::HomogeneousMaterial::setRefractiveIndex )
                , ( bp::arg("refractive_index") )
                , "Set refractive index." );
        
        }
        { //::IMaterial::isScalarMaterial
        
            typedef bool ( ::IMaterial::*isScalarMaterial_function_type)(  ) const;
            typedef bool ( HomogeneousMaterial_wrapper::*default_isScalarMaterial_function_type)(  ) const;
            
            HomogeneousMaterial_exposer.def( 
                "isScalarMaterial"
                , isScalarMaterial_function_type(&::IMaterial::isScalarMaterial)
                , default_isScalarMaterial_function_type(&HomogeneousMaterial_wrapper::default_isScalarMaterial) );
        
        }
    }

}