#include "noexct/test_suite.h"
#include "noexct/runner.h"




namespace noexct {

Runner::Runner(std::vector<std::shared_ptr<TestSuite>>& test_suites) : test_suites(test_suites) {}

std::shared_ptr<TestSuite> Runner::get_current_suite() const { 
    if(test_suites.empty())
        return nullptr;

    return test_suites.back();    
}

size_t Runner::get_total_tests() const {
    size_t total_tests = 0;
    for(const auto test_suite : test_suites){
        if(!test_suite) continue;

        total_tests += test_suite->get_test_cases().size();
    }
    return total_tests;
}

size_t Runner::get_passed_tests() const {
    size_t passed_tests = 0;
    for(const auto test_suite : test_suites){
        if(!test_suite) continue;

        passed_tests += test_suite->get_passed_count();
    }
    return passed_tests;
}

size_t Runner::get_failed_tests() const {
    size_t failed_tests = 0;
    for(const auto test_suite : test_suites){
        if(!test_suite) continue;

        failed_tests += test_suite->get_failed_count();
    }
    return failed_tests;
}

void Runner::set_reporter(std::shared_ptr<IReporter> value) { reporter = value; }
void Runner::add_test_suite(std::shared_ptr<TestSuite> test_suite) { test_suites.push_back(test_suite); }

void Runner::run_all(){
    for(auto test_suite : test_suites){
        if(!test_suite) continue;

        test_suite->setup_suite_fixture();

        reporter->report_suite_start(*test_suite);


        for(auto test_case : test_suite->get_test_cases()){
            test_suite->setup_case_fixture();
            reporter->report_test_start(*test_case);
            test_case->run();
            reporter->report_test_result(*test_case);
            test_suite->teardown_case_fixture();
        }

        reporter->report_suite_result(*test_suite);

        test_suite->teardown_suite_fixture();
    }
    reporter->report_summary(test_suites);
}
}