#pragma once

#include <vector>
#include <string>
#include <memory>

#include "noexct/Test.h"
#include "noexct/TestCase.h"
#include "noexct/SuiteInfo.h"



namespace noexct {
class TestSuite : public SuiteInfo{
public:
    explicit TestSuite(const std::string& name);

    const std::vector<std::shared_ptr<TestCase>>& get_test_cases() const;
    size_t get_passed_count() const override;
    size_t get_failed_count() const override;

    void add_fixture(std::shared_ptr<SuiteFixture> suite_fixture);
    void add_test_case(std::shared_ptr<TestCase> test_case);
    void setup();
    void teardown();

    void run();

private:
    std::shared_ptr<SuiteFixture> fixture;
    std::vector<std::shared_ptr<TestCase>> test_cases;
};

using SuiteCollection = std::vector<std::shared_ptr<TestSuite>>;
} 
