#pragma once

#include <vector>
#include <string>
#include <memory>

#include "test_case.h" 
#include "test_fixture.h" 




namespace noexct {

class TestSuite {
private:
    std::string name;
    std::vector<std::shared_ptr<ITestCase>> test_cases;
    std::shared_ptr<TestFixture> suite_fixture;
    std::shared_ptr<TestFixture> case_fixture;
public:
    TestSuite(const std::string& name);

    const std::string& get_name() const;
    const std::vector<std::shared_ptr<ITestCase>>& get_test_cases() const;
    size_t get_passed_count() const;
    size_t get_failed_count() const;

    void add_test_case(std::shared_ptr<ITestCase> test_case);
    void add_suite_fixture(std::shared_ptr<TestFixture> fixture);
    void add_case_fixture(std::shared_ptr<TestFixture> fixture);
    void setup_suite_fixture();
    void teardown_suite_fixture();
    void setup_case_fixture();
    void teardown_case_fixture();
    void run();

};

} 
