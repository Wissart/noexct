#include <memory>
#include "noexct/test_builder.h"


namespace noexct{


std::vector<std::shared_ptr<TestSuite>>& TestBuilder::get_test_suites(){
    static std::vector<std::shared_ptr<TestSuite>> test_suites;
    return test_suites;
}

void TestBuilder::add_test_suite(const char* name){
    get_test_suites().push_back(std::make_shared<TestSuite>(name));
}

void TestBuilder::add_test_case(const char* name, std::function<void()> func){
    if(auto suite = get_test_suites().back()){ 
        suite->add_test_case(std::make_shared<TestCase>(name, func)); 
    }
}

void TestBuilder::add_suite_fixture(creator_func creator){
    if(auto suite = get_test_suites().back()){ 
        suite->add_suite_fixture(std::shared_ptr<TestFixture>(creator())); 
    }
}
void TestBuilder::add_case_fixture(creator_func creator){
    if(auto suite = get_test_suites().back()){ 
        suite->add_case_fixture(std::shared_ptr<TestFixture>(creator())); 
    }
}
}