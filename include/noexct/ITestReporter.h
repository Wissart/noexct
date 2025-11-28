#pragma once

#include <memory>
#include <string>
#include <vector>

#include "CaseInfo.h"
#include "SuiteInfo.h"

namespace noexct {

enum class REPORT_LEVEL {
    SILENT,
    BASIC,
    VERBOSE
};

struct summary_report
{
    size_t suite_count;
    size_t test_count;
    size_t passed_count;
    size_t failed_count;
    double total_time;

    summary_report()
    : suite_count(0),
      test_count(0),
      passed_count(0),
      failed_count(0),
      total_time(0) {}
};


class ITestReporter{
public:
    virtual ~ITestReporter() = default;

    virtual void report_test_start(const std::shared_ptr<CaseInfo> case_info) = 0;
    virtual void report_test_result(const std::shared_ptr<CaseInfo> case_info) = 0;
    virtual void report_suite_start(const std::shared_ptr<SuiteInfo> suite_info) = 0;
    virtual void report_suite_result(const std::shared_ptr<SuiteInfo> suite_info) = 0;

    virtual void report_summary(const summary_report& summary) = 0;
};

}