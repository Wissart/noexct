#pragma once
#include <vector>
#include <memory>
#include <functional>

#include "test.h"
#include "test_suite.h"
#include "noexct_export.h"

namespace noexct{

class NOEXCT_API TestManager{
public:
    static TestManager& instance();

    std::vector<std::shared_ptr<TestSuite>>& get_suites();

    void add_suite(const char* suite_name);
    template<typename FixtureType>
    void add_suite_fixture(){
        static_assert(std::is_base_of<Test, FixtureType>::value,
                        "FixtureType must be derived from Test");
        if(auto suite = suites.back()){ 
            suite->add_fixture(std::make_shared<FixtureType>()); 
        }
    }
    template<typename TestType>
    void add_case(const char* name, 
                  typename TestCase<TestType>::TestMethod method){
        static_assert(std::is_base_of<Test, TestType>::value,
                        "TestType must be derived from Test");
        if(auto suite = suites.back()){ 
            suite->add_test_case(std::make_shared<TestCase<TestType>>(name, method)); 
        }
    }
private:
    std::vector<std::shared_ptr<TestSuite>> suites; 
};

}