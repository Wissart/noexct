#pragma once

#include "../reporter.h"


namespace noexct {

class ConsoleReporter : public IReporter{
public:
    ConsoleReporter();
    ~ConsoleReporter() override;

    virtual void report_test_start(const TestCase& test_case) override;
    virtual void report_test_result(const TestCase& test_case) override;
    virtual void report_suite_start(const TestSuite& test_suite) override;
    virtual void report_suite_result(const TestSuite& test_suite) override;

    virtual void report_summary(const std::vector<std::shared_ptr<TestSuite>>& test_suites) override;
private:
    class ConsoleWorker;
    std::unique_ptr<ConsoleWorker> console;
};

}

