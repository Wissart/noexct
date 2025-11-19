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
}