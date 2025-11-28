#define SUITE(name) \
    namespace { \
        struct SuiteInitializer_##name { \
            SuiteInitializer_##name() { \
                noexct::TestManager::instance().get_builder()->create_suite(#name); \
            } \
        } suite_init_##name; \
    };

#define TEST(testname) \
    class testname##_Test : public noexct::Test { \
    public: \
        void test_body(); \
    }; \
    namespace { \
        struct testname##_registrator { \
            testname##_registrator() { \
                noexct::TestManager::instance().get_builder()->add_case<testname##_Test>(#testname, &testname##_Test::test_body); \
            } \
        } testname##_registrator_instatnce; \
    } \
    void testname##_Test::test_body()


#define FIXTURE(classname) \
    using _SuiteFixture = classname; \
    namespace { \
        struct classname##_suite_fixture_registrator { \
            classname##_suite_fixture_registrator() { \
                noexct::TestManager::instance().get_builder()->add_suite_fixture<classname>(); \
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
                noexct::TestManager::instance().get_builder()->add_case<testname##_Test>(#testname, &testname##_Test::test_body); \
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
                noexct::TestManager::instance().get_builder()->add_case<testname##_Test>(#testname, &testname##_Test::test_body); \
            } \
        } testname##_registrator_instatnce; \
    } \
    void testname##_Test::test_body()