// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence 
//! @brief automatically generated boost::python code for PythonCoreAPI  

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "PythonCoreList.h"
#include "HomogeneousMagneticMaterial.pypp.h"

namespace bp = boost::python;

struct HomogeneousMagneticMaterial_wrapper : HomogeneousMagneticMaterial, bp::wrapper< HomogeneousMagneticMaterial > {

    HomogeneousMagneticMaterial_wrapper(HomogeneousMagneticMaterial const & arg )
    : HomogeneousMagneticMaterial( arg )
      , bp::wrapper< HomogeneousMagneticMaterial >(){
        // copy constructor
        
    }

    HomogeneousMagneticMaterial_wrapper(::std::string const & name, ::complex_t const & refractive_index, ::kvector_t const & magnetic_field )
    : HomogeneousMagneticMaterial( name, boost::ref(refractive_index), boost::ref(magnetic_field) )
      , bp::wrapper< HomogeneousMagneticMaterial >(){
        // constructor
    
    }

    HomogeneousMagneticMaterial_wrapper(::std::string const & name, double refractive_index_delta, double refractive_index_beta, ::kvector_t const & magnetic_field )
    : HomogeneousMagneticMaterial( name, refractive_index_delta, refractive_index_beta, boost::ref(magnetic_field) )
      , bp::wrapper< HomogeneousMagneticMaterial >(){
        // constructor
    
    }

    virtual ::HomogeneousMagneticMaterial * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else
            return this->HomogeneousMagneticMaterial::clone(  );
    }
    
    
    ::HomogeneousMagneticMaterial * default_clone(  ) const  {
        return HomogeneousMagneticMaterial::clone( );
    }

    virtual ::IMaterial const * createTransformedMaterial( ::Geometry::Transform3D const & transform ) const  {
        if( bp::override func_createTransformedMaterial = this->get_override( "createTransformedMaterial" ) )
            return func_createTransformedMaterial( boost::ref(transform) );
        else
            return this->HomogeneousMagneticMaterial::createTransformedMaterial( boost::ref(transform) );
    }
    
    
    ::IMaterial const * default_createTransformedMaterial( ::Geometry::Transform3D const & transform ) const  {
        return HomogeneousMagneticMaterial::createTransformedMaterial( boost::ref(transform) );
    }

    virtual bool isScalarMaterial(  ) const  {
        if( bp::override func_isScalarMaterial = this->get_override( "isScalarMaterial" ) )
            return func_isScalarMaterial(  );
        else
            return this->HomogeneousMagneticMaterial::isScalarMaterial(  );
    }
    
    
    bool default_isScalarMaterial(  ) const  {
        return HomogeneousMagneticMaterial::isScalarMaterial( );
    }

    virtual ::complex_t getRefractiveIndex(  ) const  {
        if( bp::override func_getRefractiveIndex = this->get_override( "getRefractiveIndex" ) )
            return func_getRefractiveIndex(  );
        else
            return this->HomogeneousMaterial::getRefractiveIndex(  );
    }
    
    
    ::complex_t default_getRefractiveIndex(  ) const  {
        return HomogeneousMaterial::getRefractiveIndex( );
    }

};

void register_HomogeneousMagneticMaterial_class(){

    { //::HomogeneousMagneticMaterial
        typedef bp::class_< HomogeneousMagneticMaterial_wrapper, bp::bases< HomogeneousMaterial > > HomogeneousMagneticMaterial_exposer_t;
        HomogeneousMagneticMaterial_exposer_t HomogeneousMagneticMaterial_exposer = HomogeneousMagneticMaterial_exposer_t( "HomogeneousMagneticMaterial", bp::init< std::string const &, complex_t const &, kvector_t const & >(( bp::arg("name"), bp::arg("refractive_index"), bp::arg("magnetic_field") )) );
        bp::scope HomogeneousMagneticMaterial_scope( HomogeneousMagneticMaterial_exposer );
        HomogeneousMagneticMaterial_exposer.def( bp::init< std::string const &, double, double, kvector_t const & >(( bp::arg("name"), bp::arg("refractive_index_delta"), bp::arg("refractive_index_beta"), bp::arg("magnetic_field") )) );
        { //::HomogeneousMagneticMaterial::clone
        
            typedef ::HomogeneousMagneticMaterial * ( ::HomogeneousMagneticMaterial::*clone_function_type )(  ) const;
            typedef ::HomogeneousMagneticMaterial * ( HomogeneousMagneticMaterial_wrapper::*default_clone_function_type )(  ) const;
            
            HomogeneousMagneticMaterial_exposer.def( 
                "clone"
                , clone_function_type(&::HomogeneousMagneticMaterial::clone)
                , default_clone_function_type(&HomogeneousMagneticMaterial_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::HomogeneousMagneticMaterial::createTransformedMaterial
        
            typedef ::IMaterial const * ( ::HomogeneousMagneticMaterial::*createTransformedMaterial_function_type )( ::Geometry::Transform3D const & ) const;
            typedef ::IMaterial const * ( HomogeneousMagneticMaterial_wrapper::*default_createTransformedMaterial_function_type )( ::Geometry::Transform3D const & ) const;
            
            HomogeneousMagneticMaterial_exposer.def( 
                "createTransformedMaterial"
                , createTransformedMaterial_function_type(&::HomogeneousMagneticMaterial::createTransformedMaterial)
                , default_createTransformedMaterial_function_type(&HomogeneousMagneticMaterial_wrapper::default_createTransformedMaterial)
                , ( bp::arg("transform") )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::HomogeneousMagneticMaterial::getMagneticField
        
            typedef ::kvector_t ( ::HomogeneousMagneticMaterial::*getMagneticField_function_type )(  ) const;
            
            HomogeneousMagneticMaterial_exposer.def( 
                "getMagneticField"
                , getMagneticField_function_type( &::HomogeneousMagneticMaterial::getMagneticField ) );
        
        }
        { //::HomogeneousMagneticMaterial::isScalarMaterial
        
            typedef bool ( ::HomogeneousMagneticMaterial::*isScalarMaterial_function_type )(  ) const;
            typedef bool ( HomogeneousMagneticMaterial_wrapper::*default_isScalarMaterial_function_type )(  ) const;
            
            HomogeneousMagneticMaterial_exposer.def( 
                "isScalarMaterial"
                , isScalarMaterial_function_type(&::HomogeneousMagneticMaterial::isScalarMaterial)
                , default_isScalarMaterial_function_type(&HomogeneousMagneticMaterial_wrapper::default_isScalarMaterial) );
        
        }
        { //::HomogeneousMagneticMaterial::setMagneticField
        
            typedef void ( ::HomogeneousMagneticMaterial::*setMagneticField_function_type )( ::kvector_t const & ) ;
            
            HomogeneousMagneticMaterial_exposer.def( 
                "setMagneticField"
                , setMagneticField_function_type( &::HomogeneousMagneticMaterial::setMagneticField )
                , ( bp::arg("magnetic_field") ) );
        
        }
        { //::HomogeneousMaterial::getRefractiveIndex
        
            typedef ::complex_t ( ::HomogeneousMaterial::*getRefractiveIndex_function_type )(  ) const;
            typedef ::complex_t ( HomogeneousMagneticMaterial_wrapper::*default_getRefractiveIndex_function_type )(  ) const;
            
            HomogeneousMagneticMaterial_exposer.def( 
                "getRefractiveIndex"
                , getRefractiveIndex_function_type(&::HomogeneousMaterial::getRefractiveIndex)
                , default_getRefractiveIndex_function_type(&HomogeneousMagneticMaterial_wrapper::default_getRefractiveIndex) );
        
        }
    }

}
