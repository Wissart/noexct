#pragma once

#include <vector>
#include <memory>

#include "noexct/ITestRunner.h"
#include "noexct/ITestReporter.h"
#include "TestCollection.h"


namespace noexct {


class TestRunner : public ITestRunner {
public:
    using ITestRunner::set_reporter;
    TestRunner(std::shared_ptr<TestCollection> tests);
   
    size_t get_total_tests() const;
    size_t get_passed_tests() const;
    size_t get_failed_tests() const;
    std::shared_ptr<ITestReporter> get_reporter() const;

    void set_reporter(std::shared_ptr<ITestReporter> reporter) override;
    void run_all() override;
private:
    std::shared_ptr<TestCollection> tests;
    std::shared_ptr<ITestReporter> reporter;
};

}