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


#define FIXTURE(classname) \
    using _SuiteFixture = classname; \
    namespace { \
        struct classname##_suite_fixture_registrator { \
            classname##_suite_fixture_registrator() { \
                noexct::TestManager::instance().add_suite_fixture<classname>(); \
            } \
        } classname##_suite_fixture_registrator_instatnce; \
    } \

#define TEST_SF(testname) \
    class testname##_Test : public _SuiteFixture { \
    public: \
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

#define TEST_F(fixture, testname) \
    class testname##_Test : public fixture { \
    public: \
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