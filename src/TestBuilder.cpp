#include "TestBuilder.h"




namespace noexct{

TestBuilder::TestBuilder(std::shared_ptr<TestCollection> test_collection)
: tests(test_collection),
  current_suite(nullptr) {}


void TestBuilder::create_suite(const char* name){
    current_suite = std::make_shared<TestSuite>(name);
    tests->add_suite(current_suite);
}

void TestBuilder::add_suite_fixture(std::shared_ptr<SuiteFixture> fixture){
    if(current_suite){ 
        current_suite->add_fixture(fixture); 
    }
}
void TestBuilder::add_case(std::shared_ptr<TestCase> test_case){
    tests->add_case(test_case);
}
}