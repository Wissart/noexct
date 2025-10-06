#pragma once

#include <vector>
#include <memory>

#include "test_suite.h"
#include "reporter.h"


namespace noexct {

class Runner{
private:
    std::vector<std::shared_ptr<TestSuite>> test_suites;
    std::shared_ptr<IReporter> reporter;
public:
    Runner(std::vector<std::shared_ptr<TestSuite>>& test_suites);
   
    std::shared_ptr<TestSuite> get_current_suite() const;
    size_t get_total_tests() const;
    size_t get_passed_tests() const;
    size_t get_failed_tests() const;

    void set_reporter(std::shared_ptr<IReporter> reporter);
    void add_test_suite(std::shared_ptr<TestSuite> test_suite);
    void run_all();

};

}