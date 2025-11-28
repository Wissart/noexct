#pragma once

#include "noexct/ITestReporter.h"


namespace noexct {

class ConsoleReporter : public ITestReporter{
public:
    ConsoleReporter();
    ~ConsoleReporter() override;

    void report_test_start(const std::shared_ptr<CaseInfo> case_info)  override;
    void report_test_result(const std::shared_ptr<CaseInfo> case_info) override;
    void report_suite_start(const std::shared_ptr<SuiteInfo> suite_info) override;
    void report_suite_result(const std::shared_ptr<SuiteInfo> suite_info) override;

    void report_summary(const summary_report& summary) override;
private:
    class ConsoleWorker;
    std::unique_ptr<ConsoleWorker> console;
};

}

