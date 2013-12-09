#ifndef _IFUNCTIONALTEST_H
#define _IFUNCTIONALTEST_H


#include "Simulation.h"
#include <boost/shared_ptr.hpp>
#include <string>


class IFunctionalTest
{
public:
    virtual ~IFunctionalTest() {}
    virtual void runTest() =0;
};


//! functional test info and description
class FunctionalTestInfo
{
public:
    FunctionalTestInfo()
        : m_threshold(0) {  }

    FunctionalTestInfo(const std::string &name, const std::string &description,
              const std::string &reference, double threshold )
        : m_name(name)
        , m_description(description)
        , m_reference_file(reference)
        , m_threshold(threshold) {  }

    std::string m_name;
    std::string m_description;
    std::string m_reference_file;
    double m_threshold;
};


//! basic functional test
class FunctionalTest : public IFunctionalTest
{
public:
    enum TestResult { SUCCESS, FAILED};

    FunctionalTest(const FunctionalTestInfo &info);
    ~FunctionalTest();

    Simulation *getSimulation() { return m_simulation; }
    const OutputData<double> *getResult() const { return m_simulation->getOutputData(); }
    const OutputData<double> *getReference() const { return m_reference; }
    std::string getName() const { return m_info.m_name; }
    std::string getDescription() const { return m_info.m_description; }
    void runTest();
    int analyseResults();

private:
    FunctionalTestInfo m_info;
    Simulation *m_simulation;
    OutputData<double> *m_reference;
};

typedef boost::shared_ptr<FunctionalTest> FunctionalTest_t;


#endif
