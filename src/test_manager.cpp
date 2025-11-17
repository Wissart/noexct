#include <memory>
#include "noexct/test_manager.h"


namespace noexct{


TestManager& TestManager::instance(){
    static TestManager manager;
    return manager;
}

std::vector<std::shared_ptr<TestSuite>>& TestManager::get_suites() { return suites; }

void TestManager::add_suite(const char* name){
    suites.push_back(std::make_shared<TestSuite>(name));
}

void TestManager::add_suite_fixture(creator_func creator){
    if(auto suite = suites.back()){ 
        suite->add_suite_fixture(std::shared_ptr<TestFixture>(creator())); 
    }
}
void TestManager::add_case_fixture(creator_func creator){
    if(auto suite = suites.back()){ 
        suite->add_case_fixture(std::shared_ptr<TestFixture>(creator())); 
    }
}
}