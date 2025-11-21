#pragma once

#include <vector>
#include <string>
#include <memory>

#include "test.h"
#include "test_case.h"




namespace noexct {

class TestSuite {
public:
    TestSuite(const std::string& name);

    const std::string& get_name() const;
    const std::vector<std::shared_ptr<ITestCase>>& get_test_cases() const;
    size_t get_passed_count() const;
    size_t get_failed_count() const;

    void add_fixture(std::shared_ptr<SuiteFixture> suite_fixture);
    void add_test_case(std::shared_ptr<ITestCase> test_case);
    void setup();
    void teardown();

    void run();

private:
    std::string name;
    std::shared_ptr<SuiteFixture> fixture;
    std::vector<std::shared_ptr<ITestCase>> test_cases;
};

} 
