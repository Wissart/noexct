#pragma once
#include <vector>
#include <memory>
#include <functional>

#include "test_fixture.h"
#include "test_suite.h"
#include "noexct_export.h"

namespace noexct{

class NOEXCT_API TestBuilder{
public:
    using creator_func = TestFixture*(*)();

    static std::vector<std::shared_ptr<TestSuite>>& get_test_suites();
    
    static void add_test_suite(const char* name);
    static void add_test_case(const char* name, std::function<void()> func);
    static void add_suite_fixture(creator_func creator);
    static void add_case_fixture(creator_func creator);
};

}

#define TEST_SUITE(name) \
    namespace { \
        struct SuiteInitializer_##name { \
            SuiteInitializer_##name() { \
                noexct::TestBuilder::add_test_suite(#name); \
            } \
        } suite_init_##name; \
    };

#define TEST_CASE(name) \
    void name(); \
    namespace { \
        struct TestRegistrar_##name { \
            TestRegistrar_##name() { \
                noexct::TestBuilder::add_test_case(#name, &name); \
            } \
        } TestRegistrar_##name; \
    } \
    void name()

#define SUITE_FIXTURE(class_name) \
    namespace { \
        struct SuiteFixtureInitializer_##class_name { \
            static noexct::TestFixture* create_instance(){ \
                return new class_name(); \
            } \
            SuiteFixtureInitializer_##class_name() { \
                noexct::TestBuilder::add_suite_fixture(&create_instance); \
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
                noexct::TestBuilder::add_case_fixture(&create_instance); \
            } \
        } case_fixture_init_##class_name; \
    };