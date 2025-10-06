#pragma once

#include <string>
#include <vector>

#include "noexct/test_case.h"
#include "noexct/test_suite.h"

namespace noexct {

enum class REPORT_LEVEL {
    SILENT,
    BASIC,
    VERBOSE
};

class IReporter{
public:
    virtual ~IReporter() = default;

    virtual void report_test_start(const TestCase& test_case) = 0;
    virtual void report_test_result(const TestCase& test_case) = 0;
    virtual void report_suite_start(const TestSuite& test_suite) = 0;
    virtual void report_suite_result(const TestSuite& test_suite) = 0;

    virtual void report_summary(const std::vector<std::shared_ptr<TestSuite>>& test_suties) = 0;
};

}