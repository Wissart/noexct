#pragma once

#include <vector>
#include <memory>

#include "noexct/ITestBuilder.h"
#include "TestCollection.h"

namespace noexct{
class TestBuilder : public ITestBuilder{
public:
    TestBuilder(std::shared_ptr<TestCollection> test_collection);

    void create_suite(const char* suite_name) override;
    void add_suite_fixture(std::shared_ptr<SuiteFixture> fixture) override;
    void add_case(std::shared_ptr<TestCase> test_case) override;
private:
    std::shared_ptr<TestCollection> tests;
    std::shared_ptr<TestSuite> current_suite;

};

}