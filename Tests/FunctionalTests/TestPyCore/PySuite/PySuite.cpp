#include "pyscript_functional_tests.h"

//! The main function of PyScript to run pyscript functional tests
int main(int argc, char **argv)
{
    std::string test_name;
    if(argc > 1) {
        test_name = std::string(argv[1]);
    }
    return PYSCRIPT_FUNCTIONAL_TEST(test_name);
}