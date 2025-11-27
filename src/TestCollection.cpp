#include "TestCollection.h"




namespace noexct{
TestCollection::TestCollection() {}

TestCollection::~TestCollection() = default;

const SuiteCollection& TestCollection::get_suites() const { return suites; } 

void TestCollection::add_suite(std::shared_ptr<TestSuite> test_suite){
    suites.push_back(test_suite);
}
void TestCollection::add_case(std::shared_ptr<TestCase> test_case){
    if(auto suite = suites.back()){
        suite->add_test_case(test_case);
    }
}

}