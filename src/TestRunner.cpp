#include "TestRunner.h"


namespace noexct {

TestRunner::TestRunner(std::shared_ptr<TestCollection> test_collection) : tests(test_collection) {}

std::shared_ptr<ITestReporter> TestRunner::get_reporter() const { return reporter; }

size_t TestRunner::get_total_tests() const {
    size_t total_tests = 0;
    for(const auto test_suite : tests->get_suites()){
        if(!test_suite) continue;

        total_tests += test_suite->get_test_cases().size();
    }
    return total_tests;
}

size_t TestRunner::get_passed_tests() const {
    size_t passed_tests = 0;
    for(const auto test_suite : tests->get_suites()){
        if(!test_suite) continue;

        passed_tests += test_suite->get_passed_count();
    }
    return passed_tests;
}

size_t TestRunner::get_failed_tests() const {
    size_t failed_tests = 0;
    for(const auto test_suite : tests->get_suites()){
        if(!test_suite) continue;

        failed_tests += test_suite->get_failed_count();
    }
    return failed_tests;
}

void TestRunner::set_reporter(std::shared_ptr<ITestReporter> value) { reporter = value; }

void TestRunner::run_all(){
    summary_report summary;
    for(auto test_suite : tests->get_suites()){
        if(!test_suite) continue;

        
        reporter->report_suite_start(test_suite);
        test_suite->setup();

        for(auto test_case : test_suite->get_test_cases()){
            reporter->report_test_start(test_case);
            test_case->run();
            reporter->report_test_result(test_case);

            summary.test_count++;
            summary.total_time += test_case->get_duration();
            if(test_case->is_passed())
                summary.passed_count++;
            else
                summary.failed_count++;
        }
        test_suite->teardown();
        reporter->report_suite_result(test_suite);
        summary.suite_count++;

    }
    reporter->report_summary(summary);
}
}