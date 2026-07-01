#pragma once

#include <memory>

#include "Test.h"
#include "TestCase.h"
#include "noexct_export.h"

namespace noexct{
class NOEXCT_API ITestBuilder{
public:
    virtual ~ITestBuilder() = default;

    virtual void create_suite(const char* suite_name) = 0;
    virtual void add_suite_fixture(std::shared_ptr<SuiteFixture> fixture) = 0;
    virtual void add_case(std::shared_ptr<TestCase> test_case) = 0;

    template<typename FixtureType>
    void add_suite_fixture(){
        static_assert(std::is_base_of<SuiteFixture, FixtureType>::value,
                        "FixtureType must be derived from SuiteFixture");
        add_suite_fixture(std::make_shared<FixtureType>()); 
    }
    template<typename TestType>
    void add_case(const char* name, 
                  typename TypedTestCase<TestType>::TestMethod method){
        static_assert(std::is_base_of<Test, TestType>::value,
                        "TestType must be derived from Test");
        add_case(std::make_shared<TypedTestCase<TestType>>(name, method));
    }

};

}