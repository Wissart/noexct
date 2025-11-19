#pragma once
#include <vector>
#include <memory>
#include <functional>

#include "test.h"
#include "test_fixture.h"
#include "test_suite.h"
#include "noexct_export.h"

namespace noexct{

class NOEXCT_API TestManager{
public:
    using creator_func = TestFixture*(*)();

    static TestManager& instance();

    std::vector<std::shared_ptr<TestSuite>>& get_suites();

    void add_suite(const char* suite_name);
    template<typename TestType>
    void add_case(const char* name, 
                  typename TestCase<TestType>::TestMethod method){
        static_assert(std::is_base_of<Test, TestType>::value,
                        "TestType must be derived from Test");
        if(auto suite = suites.back()){ 
            suite->add_test_case(std::make_shared<TestCase<TestType>>(name, method)); 
        }
    }
    void add_suite_fixture(creator_func creator);
    void add_case_fixture(creator_func creator);
private:
    std::vector<std::shared_ptr<TestSuite>> suites; 
};

}

#define TEST_SUITE(name) \
    namespace { \
        struct SuiteInitializer_##name { \
            SuiteInitializer_##name() { \
                noexct::TestManager::instance().add_suite(#name); \
            } \
        } suite_init_##name; \
    };

#define TEST_CASE(testname) \
    class testname##_Test : public noexct::Test { \
    public: \
        testname##_Test() = default; \
        void test_body(); \
    }; \
    namespace { \
        struct testname##_registrator { \
            testname##_registrator() { \
                noexct::TestManager::instance().add_case<testname##_Test>(#testname, &testname##_Test::test_body); \
            } \
        } testname##_registrator_instatnce; \
    } \
    void testname##_Test::test_body()

#define SUITE_FIXTURE(class_name) \
    namespace { \
        struct SuiteFixtureInitializer_##class_name { \
            static noexct::TestFixture* create_instance(){ \
                return new class_name(); \
            } \
            SuiteFixtureInitializer_##class_name() { \
                noexct::TestManager::instance().add_suite_fixture(&create_instance); \
            } \
        } suite_fixture_init_##class_name; \
    };

#define CASE_FIXTURE(class_name) \
    namespace { \
        struct CaseFixtureInitializer_##class_name { \
            static noexct::TestFixture* create_instance(){ \
                return new class_name(); \
            } \
            CaseFixtureInitializer_##class_name() { \
                noexct::TestManager::instance().add_case_fixture(&create_instance); \
            } \
        } case_fixture_init_##class_name; \
    };