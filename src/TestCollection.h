#pragma once

#include <memory>

#include "TestSuite.h"

namespace noexct{
class TestCollection{
public:
    TestCollection();
    ~TestCollection();

    const SuiteCollection& get_suites() const;

    void add_suite(std::shared_ptr<TestSuite> test_suite);
    void add_case(std::shared_ptr<TestCase> test_case);
private:
    SuiteCollection suites;
};
}