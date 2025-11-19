#include "noexct/test_suite.h"


namespace noexct {

TestSuite::TestSuite(const std::string& name) 
: name(name) {}

const std::string& TestSuite::get_name() const { return name; }
const std::vector<std::shared_ptr<ITestCase>>& TestSuite::get_test_cases() const { return test_cases;}

size_t TestSuite::get_passed_count() const {
    size_t passed_count = 0;
    for(const auto test_case : test_cases){
        if(test_case && test_case->is_passed())
            passed_count++;
    }
    return passed_count;
}

size_t TestSuite::get_failed_count() const {
    size_t failed_count = 0;
    for(const auto test_case : test_cases){
        if(test_case && !test_case->is_passed())
            failed_count++;
    }
    return failed_count;
}

void TestSuite::add_test_case(std::shared_ptr<ITestCase> test_case){
    test_cases.push_back(test_case);
}

void TestSuite::run(){
    for(auto test_case : test_cases){
        if(test_case) {
            test_case->run();
        }
    }
}
}
