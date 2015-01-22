// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence
//! @brief Automatically generated boost::python code for PythonCoreAPI

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "__call_policies.pypp.hpp"
#include "__convenience.pypp.hpp"
#include "PythonCoreList.h"
#include "Layer.pypp.h"

namespace bp = boost::python;

struct Layer_wrapper : Layer, bp::wrapper< Layer > {

    Layer_wrapper( )
    : Layer( )
      , bp::wrapper< Layer >(){
        // null constructor
    m_pyobj = 0;
    }

    Layer_wrapper(::IMaterial const & material, double thickness=0 )
    : Layer( boost::ref(material), thickness )
      , bp::wrapper< Layer >(){
        // constructor
    m_pyobj = 0;
    }

    Layer_wrapper(::Layer const & other )
    : Layer( boost::ref(other) )
      , bp::wrapper< Layer >(){
        // copy constructor
    m_pyobj = 0;
    }

    virtual void addLayout( ::ILayout const & decoration ) {
        if( bp::override func_addLayout = this->get_override( "addLayout" ) )
            func_addLayout( boost::ref(decoration) );
        else{
            this->Layer::addLayout( boost::ref(decoration) );
        }
    }
    
    void default_addLayout( ::ILayout const & decoration ) {
        Layer::addLayout( boost::ref(decoration) );
    }

    virtual ::Layer * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->Layer::clone(  );
        }
    }
    
    ::Layer * default_clone(  ) const  {
        return Layer::clone( );
    }

    virtual ::Layer * cloneInvertB(  ) const  {
        if( bp::override func_cloneInvertB = this->get_override( "cloneInvertB" ) )
            return func_cloneInvertB(  );
        else{
            return this->Layer::cloneInvertB(  );
        }
    }
    
    ::Layer * default_cloneInvertB(  ) const  {
        return Layer::cloneInvertB( );
    }

    virtual ::ILayout const * getLayout( ::std::size_t i ) const  {
        if( bp::override func_getLayout = this->get_override( "getLayout" ) )
            return func_getLayout( i );
        else{
            return this->Layer::getLayout( i );
        }
    }
    
    ::ILayout const * default_getLayout( ::std::size_t i ) const  {
        return Layer::getLayout( i );
    }

    virtual ::IMaterial const * getMaterial(  ) const  {
        if( bp::override func_getMaterial = this->get_override( "getMaterial" ) )
            return func_getMaterial(  );
        else{
            return this->Layer::getMaterial(  );
        }
    }
    
    ::IMaterial const * default_getMaterial(  ) const  {
        return Layer::getMaterial( );
    }

    virtual ::complex_t getRefractiveIndex(  ) const  {
        if( bp::override func_getRefractiveIndex = this->get_override( "getRefractiveIndex" ) )
            return func_getRefractiveIndex(  );
        else{
            return this->Layer::getRefractiveIndex(  );
        }
    }
    
    ::complex_t default_getRefractiveIndex(  ) const  {
        return Layer::getRefractiveIndex( );
    }

    virtual double getThickness(  ) const  {
        if( bp::override func_getThickness = this->get_override( "getThickness" ) )
            return func_getThickness(  );
        else{
            return this->Layer::getThickness(  );
        }
    }
    
    double default_getThickness(  ) const  {
        return Layer::getThickness( );
    }

    virtual void setMaterial( ::IMaterial const & material ) {
        if( bp::override func_setMaterial = this->get_override( "setMaterial" ) )
            func_setMaterial( boost::ref(material) );
        else{
            this->Layer::setMaterial( boost::ref(material) );
        }
    }
    
    void default_setMaterial( ::IMaterial const & material ) {
        Layer::setMaterial( boost::ref(material) );
    }

    virtual void setMaterialAndThickness( ::IMaterial const & material, double thickness ) {
        if( bp::override func_setMaterialAndThickness = this->get_override( "setMaterialAndThickness" ) )
            func_setMaterialAndThickness( boost::ref(material), thickness );
        else{
            this->Layer::setMaterialAndThickness( boost::ref(material), thickness );
        }
    }
    
    void default_setMaterialAndThickness( ::IMaterial const & material, double thickness ) {
        Layer::setMaterialAndThickness( boost::ref(material), thickness );
    }

    virtual void setThickness( double thickness ) {
        if( bp::override func_setThickness = this->get_override( "setThickness" ) )
            func_setThickness( thickness );
        else{
            this->Layer::setThickness( thickness );
        }
    }
    
    void default_setThickness( double thickness ) {
        Layer::setThickness( thickness );
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

    virtual void clearParameterPool(  ) {
        if( bp::override func_clearParameterPool = this->get_override( "clearParameterPool" ) )
            func_clearParameterPool(  );
        else{
            this->IParameterized::clearParameterPool(  );
        }
    }
    
    void default_clearParameterPool(  ) {
        IParameterized::clearParameterPool( );
    }

    virtual bool containsMagneticMaterial(  ) const  {
        if( bp::override func_containsMagneticMaterial = this->get_override( "containsMagneticMaterial" ) )
            return func_containsMagneticMaterial(  );
        else{
            return this->ISample::containsMagneticMaterial(  );
        }
    }
    
    bool default_containsMagneticMaterial(  ) const  {
        return ISample::containsMagneticMaterial( );
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

    virtual ::ICompositeSample * getCompositeSample(  ) {
        if( bp::override func_getCompositeSample = this->get_override( "getCompositeSample" ) )
            return func_getCompositeSample(  );
        else{
            return this->ICompositeSample::getCompositeSample(  );
        }
    }
    
    ::ICompositeSample * default_getCompositeSample(  ) {
        return ICompositeSample::getCompositeSample( );
    }

    virtual ::ICompositeSample const * getCompositeSample(  ) const  {
        if( bp::override func_getCompositeSample = this->get_override( "getCompositeSample" ) )
            return func_getCompositeSample(  );
        else{
            return this->ICompositeSample::getCompositeSample(  );
        }
    }
    
    ::ICompositeSample const * default_getCompositeSample(  ) const  {
        return ICompositeSample::getCompositeSample( );
    }

    virtual bool preprocess(  ) {
        if( bp::override func_preprocess = this->get_override( "preprocess" ) )
            return func_preprocess(  );
        else{
            return this->ISample::preprocess(  );
        }
    }
    
    bool default_preprocess(  ) {
        return ISample::preprocess( );
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

    virtual void printSampleTree(  ) {
        if( bp::override func_printSampleTree = this->get_override( "printSampleTree" ) )
            func_printSampleTree(  );
        else{
            this->ISample::printSampleTree(  );
        }
    }
    
    void default_printSampleTree(  ) {
        ISample::printSampleTree( );
    }

    virtual void registerParameter( ::std::string const & name, double * parpointer ) {
        namespace bpl = boost::python;
        if( bpl::override func_registerParameter = this->get_override( "registerParameter" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_registerParameter.ptr(), name, parpointer );
        }
        else{
            IParameterized::registerParameter( name, parpointer );
        }
    }
    
    static void default_registerParameter( ::IParameterized & inst, ::std::string const & name, long unsigned int parpointer ){
        if( dynamic_cast< Layer_wrapper * >( boost::addressof( inst ) ) ){
            inst.::IParameterized::registerParameter(name, reinterpret_cast< double * >( parpointer ));
        }
        else{
            inst.registerParameter(name, reinterpret_cast< double * >( parpointer ));
        }
    }

    virtual bool setParameterValue( ::std::string const & name, double value ) {
        if( bp::override func_setParameterValue = this->get_override( "setParameterValue" ) )
            return func_setParameterValue( name, value );
        else{
            return this->IParameterized::setParameterValue( name, value );
        }
    }
    
    bool default_setParameterValue( ::std::string const & name, double value ) {
        return IParameterized::setParameterValue( name, value );
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

    virtual ::std::size_t size(  ) const  {
        if( bp::override func_size = this->get_override( "size" ) )
            return func_size(  );
        else{
            return this->ICompositeSample::size(  );
        }
    }
    
    ::std::size_t default_size(  ) const  {
        return ICompositeSample::size( );
    }

    virtual void transferToCPP(  ) {
        
        if( !this->m_pyobj) {
            this->m_pyobj = boost::python::detail::wrapper_base_::get_owner(*this);
            Py_INCREF(this->m_pyobj);
        }
        
        if( bp::override func_transferToCPP = this->get_override( "transferToCPP" ) )
            func_transferToCPP(  );
        else{
            this->ICloneable::transferToCPP(  );
        }
    }
    
    void default_transferToCPP(  ) {
        
        if( !this->m_pyobj) {
            this->m_pyobj = boost::python::detail::wrapper_base_::get_owner(*this);
            Py_INCREF(this->m_pyobj);
        }
        
        ICloneable::transferToCPP( );
    }

    PyObject* m_pyobj;

};

void register_Layer_class(){

    { //::Layer
        typedef bp::class_< Layer_wrapper, bp::bases< ICompositeSample >, std::auto_ptr< Layer_wrapper >, boost::noncopyable > Layer_exposer_t;
        Layer_exposer_t Layer_exposer = Layer_exposer_t( "Layer", bp::init< >() );
        bp::scope Layer_scope( Layer_exposer );
        Layer_exposer.def( bp::init< IMaterial const &, bp::optional< double > >(( bp::arg("material"), bp::arg("thickness")=0 )) );
        Layer_exposer.def( bp::init< Layer const & >(( bp::arg("other") )) );
        { //::Layer::addLayout
        
            typedef void ( ::Layer::*addLayout_function_type)( ::ILayout const & ) ;
            typedef void ( Layer_wrapper::*default_addLayout_function_type)( ::ILayout const & ) ;
            
            Layer_exposer.def( 
                "addLayout"
                , addLayout_function_type(&::Layer::addLayout)
                , default_addLayout_function_type(&Layer_wrapper::default_addLayout)
                , ( bp::arg("decoration") ) );
        
        }
        { //::Layer::clone
        
            typedef ::Layer * ( ::Layer::*clone_function_type)(  ) const;
            typedef ::Layer * ( Layer_wrapper::*default_clone_function_type)(  ) const;
            
            Layer_exposer.def( 
                "clone"
                , clone_function_type(&::Layer::clone)
                , default_clone_function_type(&Layer_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::Layer::cloneInvertB
        
            typedef ::Layer * ( ::Layer::*cloneInvertB_function_type)(  ) const;
            typedef ::Layer * ( Layer_wrapper::*default_cloneInvertB_function_type)(  ) const;
            
            Layer_exposer.def( 
                "cloneInvertB"
                , cloneInvertB_function_type(&::Layer::cloneInvertB)
                , default_cloneInvertB_function_type(&Layer_wrapper::default_cloneInvertB)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::Layer::createLayoutSimulation
        
            typedef ::LayerDWBASimulation * ( ::Layer::*createLayoutSimulation_function_type)( ::std::size_t ) const;
            
            Layer_exposer.def( 
                "createLayoutSimulation"
                , createLayoutSimulation_function_type( &::Layer::createLayoutSimulation )
                , ( bp::arg("layout_index") )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::Layer::getLayout
        
            typedef ::ILayout const * ( ::Layer::*getLayout_function_type)( ::std::size_t ) const;
            typedef ::ILayout const * ( Layer_wrapper::*default_getLayout_function_type)( ::std::size_t ) const;
            
            Layer_exposer.def( 
                "getLayout"
                , getLayout_function_type(&::Layer::getLayout)
                , default_getLayout_function_type(&Layer_wrapper::default_getLayout)
                , ( bp::arg("i") )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::Layer::getMaterial
        
            typedef ::IMaterial const * ( ::Layer::*getMaterial_function_type)(  ) const;
            typedef ::IMaterial const * ( Layer_wrapper::*default_getMaterial_function_type)(  ) const;
            
            Layer_exposer.def( 
                "getMaterial"
                , getMaterial_function_type(&::Layer::getMaterial)
                , default_getMaterial_function_type(&Layer_wrapper::default_getMaterial)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::Layer::getNumberOfLayers
        
            typedef ::std::size_t ( ::Layer::*getNumberOfLayers_function_type)(  ) const;
            
            Layer_exposer.def( 
                "getNumberOfLayers"
                , getNumberOfLayers_function_type( &::Layer::getNumberOfLayers ) );
        
        }
        { //::Layer::getNumberOfLayouts
        
            typedef ::std::size_t ( ::Layer::*getNumberOfLayouts_function_type)(  ) const;
            
            Layer_exposer.def( 
                "getNumberOfLayouts"
                , getNumberOfLayouts_function_type( &::Layer::getNumberOfLayouts ) );
        
        }
        { //::Layer::getRefractiveIndex
        
            typedef ::complex_t ( ::Layer::*getRefractiveIndex_function_type)(  ) const;
            typedef ::complex_t ( Layer_wrapper::*default_getRefractiveIndex_function_type)(  ) const;
            
            Layer_exposer.def( 
                "getRefractiveIndex"
                , getRefractiveIndex_function_type(&::Layer::getRefractiveIndex)
                , default_getRefractiveIndex_function_type(&Layer_wrapper::default_getRefractiveIndex) );
        
        }
        { //::Layer::getThickness
        
            typedef double ( ::Layer::*getThickness_function_type)(  ) const;
            typedef double ( Layer_wrapper::*default_getThickness_function_type)(  ) const;
            
            Layer_exposer.def( 
                "getThickness"
                , getThickness_function_type(&::Layer::getThickness)
                , default_getThickness_function_type(&Layer_wrapper::default_getThickness) );
        
        }
        { //::Layer::getTotalAbundance
        
            typedef double ( ::Layer::*getTotalAbundance_function_type)(  ) const;
            
            Layer_exposer.def( 
                "getTotalAbundance"
                , getTotalAbundance_function_type( &::Layer::getTotalAbundance ) );
        
        }
        { //::Layer::getTotalParticleSurfaceDensity
        
            typedef double ( ::Layer::*getTotalParticleSurfaceDensity_function_type)( ::std::size_t ) const;
            
            Layer_exposer.def( 
                "getTotalParticleSurfaceDensity"
                , getTotalParticleSurfaceDensity_function_type( &::Layer::getTotalParticleSurfaceDensity )
                , ( bp::arg("layout_index") ) );
        
        }
        { //::Layer::setMaterial
        
            typedef void ( ::Layer::*setMaterial_function_type)( ::IMaterial const & ) ;
            typedef void ( Layer_wrapper::*default_setMaterial_function_type)( ::IMaterial const & ) ;
            
            Layer_exposer.def( 
                "setMaterial"
                , setMaterial_function_type(&::Layer::setMaterial)
                , default_setMaterial_function_type(&Layer_wrapper::default_setMaterial)
                , ( bp::arg("material") ) );
        
        }
        { //::Layer::setMaterialAndThickness
        
            typedef void ( ::Layer::*setMaterialAndThickness_function_type)( ::IMaterial const &,double ) ;
            typedef void ( Layer_wrapper::*default_setMaterialAndThickness_function_type)( ::IMaterial const &,double ) ;
            
            Layer_exposer.def( 
                "setMaterialAndThickness"
                , setMaterialAndThickness_function_type(&::Layer::setMaterialAndThickness)
                , default_setMaterialAndThickness_function_type(&Layer_wrapper::default_setMaterialAndThickness)
                , ( bp::arg("material"), bp::arg("thickness") ) );
        
        }
        { //::Layer::setNumberOfLayers
        
            typedef void ( ::Layer::*setNumberOfLayers_function_type)( ::std::size_t ) ;
            
            Layer_exposer.def( 
                "setNumberOfLayers"
                , setNumberOfLayers_function_type( &::Layer::setNumberOfLayers )
                , ( bp::arg("n_layers") ) );
        
        }
        { //::Layer::setThickness
        
            typedef void ( ::Layer::*setThickness_function_type)( double ) ;
            typedef void ( Layer_wrapper::*default_setThickness_function_type)( double ) ;
            
            Layer_exposer.def( 
                "setThickness"
                , setThickness_function_type(&::Layer::setThickness)
                , default_setThickness_function_type(&Layer_wrapper::default_setThickness)
                , ( bp::arg("thickness") ) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type)(  ) ;
            typedef bool ( Layer_wrapper::*default_areParametersChanged_function_type)(  ) ;
            
            Layer_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&Layer_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type)(  ) ;
            typedef void ( Layer_wrapper::*default_clearParameterPool_function_type)(  ) ;
            
            Layer_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&Layer_wrapper::default_clearParameterPool) );
        
        }
        { //::ISample::containsMagneticMaterial
        
            typedef bool ( ::ISample::*containsMagneticMaterial_function_type)(  ) const;
            typedef bool ( Layer_wrapper::*default_containsMagneticMaterial_function_type)(  ) const;
            
            Layer_exposer.def( 
                "containsMagneticMaterial"
                , containsMagneticMaterial_function_type(&::ISample::containsMagneticMaterial)
                , default_containsMagneticMaterial_function_type(&Layer_wrapper::default_containsMagneticMaterial) );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type)(  ) const;
            typedef ::ParameterPool * ( Layer_wrapper::*default_createParameterTree_function_type)(  ) const;
            
            Layer_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&Layer_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::ICompositeSample::getCompositeSample
        
            typedef ::ICompositeSample * ( ::ICompositeSample::*getCompositeSample_function_type)(  ) ;
            typedef ::ICompositeSample * ( Layer_wrapper::*default_getCompositeSample_function_type)(  ) ;
            
            Layer_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ICompositeSample::getCompositeSample)
                , default_getCompositeSample_function_type(&Layer_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ICompositeSample::getCompositeSample
        
            typedef ::ICompositeSample const * ( ::ICompositeSample::*getCompositeSample_function_type)(  ) const;
            typedef ::ICompositeSample const * ( Layer_wrapper::*default_getCompositeSample_function_type)(  ) const;
            
            Layer_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ICompositeSample::getCompositeSample)
                , default_getCompositeSample_function_type(&Layer_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ISample::preprocess
        
            typedef bool ( ::ISample::*preprocess_function_type)(  ) ;
            typedef bool ( Layer_wrapper::*default_preprocess_function_type)(  ) ;
            
            Layer_exposer.def( 
                "preprocess"
                , preprocess_function_type(&::ISample::preprocess)
                , default_preprocess_function_type(&Layer_wrapper::default_preprocess) );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type)(  ) const;
            typedef void ( Layer_wrapper::*default_printParameters_function_type)(  ) const;
            
            Layer_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&Layer_wrapper::default_printParameters) );
        
        }
        { //::ISample::printSampleTree
        
            typedef void ( ::ISample::*printSampleTree_function_type)(  ) ;
            typedef void ( Layer_wrapper::*default_printSampleTree_function_type)(  ) ;
            
            Layer_exposer.def( 
                "printSampleTree"
                , printSampleTree_function_type(&::ISample::printSampleTree)
                , default_printSampleTree_function_type(&Layer_wrapper::default_printSampleTree) );
        
        }
        { //::IParameterized::registerParameter
        
            typedef void ( *default_registerParameter_function_type )( ::IParameterized &,::std::string const &,long unsigned int );
            
            Layer_exposer.def( 
                "registerParameter"
                , default_registerParameter_function_type( &Layer_wrapper::default_registerParameter )
                , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer") ) );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type)( ::std::string const &,double ) ;
            typedef bool ( Layer_wrapper::*default_setParameterValue_function_type)( ::std::string const &,double ) ;
            
            Layer_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&Layer_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type)(  ) ;
            typedef void ( Layer_wrapper::*default_setParametersAreChanged_function_type)(  ) ;
            
            Layer_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&Layer_wrapper::default_setParametersAreChanged) );
        
        }
        { //::ICompositeSample::size
        
            typedef ::std::size_t ( ::ICompositeSample::*size_function_type)(  ) const;
            typedef ::std::size_t ( Layer_wrapper::*default_size_function_type)(  ) const;
            
            Layer_exposer.def( 
                "size"
                , size_function_type(&::ICompositeSample::size)
                , default_size_function_type(&Layer_wrapper::default_size) );
        
        }
        { //::ICloneable::transferToCPP
        
            typedef void ( ::ICloneable::*transferToCPP_function_type)(  ) ;
            typedef void ( Layer_wrapper::*default_transferToCPP_function_type)(  ) ;
            
            Layer_exposer.def( 
                "transferToCPP"
                , transferToCPP_function_type(&::ICloneable::transferToCPP)
                , default_transferToCPP_function_type(&Layer_wrapper::default_transferToCPP) );
        
        }
    }

}
