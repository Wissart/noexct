#include <iostream>
#include <string>
#include <sstream>

#ifdef _WIN32
    #include <windows.h>
#endif

#include "noexct/reporters/console_reporter.h"

#if _WIN32
    #define SET_COLOR(color) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color)
    #define GREEN FOREGROUND_GREEN | FOREGROUND_INTENSITY
    #define RED FOREGROUND_RED | FOREGROUND_INTENSITY
    #define RESET FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
#else
    #define SET_COLOR(color) std::cout << color
    #define GREEN = "\033[32m";
    #define RED = "\033[31m";
    #define RESET = "\033[0m";
#endif

namespace noexct {

class ConsoleReporter::ConsoleWorker{
public:
    REPORT_LEVEL level = REPORT_LEVEL::BASIC;
public:
    void print(const std::string& message){
        std::cout << message;
    }
    void print(const char* message){
        std::cout << message;
    }
    void printL(const std::string& message){
        std::cout << message << '\n';
    }
    void printL(const char* message){
        std::cout << message << '\n';
    }
    void print_test_start(const ITestCase&){
        return;
    }
    void print_test_result(const ITestCase& test_case){

        if(test_case.is_passed()){
            SET_COLOR(GREEN);
            std::cout << "PASS";
            SET_COLOR(RESET);
            std::cout << ": " << test_case.get_name() << "(" << test_case.get_duration() << "ms)" << "\n";
        }
        else{
            SET_COLOR(RED);
            std::cout << "FAIL";
            SET_COLOR(RESET);
            std::cout << ": " << test_case.get_name() << "(" << test_case.get_duration() << "ms)" << " - " << test_case.get_error_message() << "\n";
        }
    }
    void print_suite_start(const TestSuite& test_suite){
        std::string message;

        message = "Running test suite: " + test_suite.get_name() + "\n";
        print(message);
    }
    void print_suite_result(const TestSuite&){
        return;
    }
    void print_summary(const std::vector<std::shared_ptr<TestSuite>>& test_suites){
        size_t suite_count = test_suites.size();

        size_t test_count = 0;
        size_t passed_count = 0;
        size_t failed_count  = 0;
        double total_time = 0;

        for(auto test_suite : test_suites){
            passed_count += test_suite->get_passed_count();
            failed_count += test_suite->get_failed_count();

            for(auto test_case : test_suite->get_test_cases()){
                test_count++;
                total_time += test_case->get_duration();
            }
        }

        printL(" ");
        printL("--- SUMMARY ---");
        
        std::stringstream message;
        message << "Suites: " << suite_count << ", Testes: " << test_count << ", Passed: " << passed_count << ", Failed: " << failed_count << "\n";
        message << "Total time: (" << total_time << "ms)"<< "\n";

        print(message.str());
    }
};

ConsoleReporter::ConsoleReporter() : console(std::make_unique<ConsoleWorker>()){}
ConsoleReporter::~ConsoleReporter() = default;

void ConsoleReporter::report_test_start(const ITestCase& test_case){
    console->print_test_start(test_case);
}
void ConsoleReporter::report_test_result(const ITestCase& test_case){
    console->print_test_result(test_case);
}
void ConsoleReporter::report_suite_start(const TestSuite& test_suite){
    console->print_suite_start(test_suite);
}
void ConsoleReporter::report_suite_result(const TestSuite& test_suite){
    console->print_suite_result(test_suite);
}

void ConsoleReporter::report_summary(const std::vector<std::shared_ptr<TestSuite>>& test_suites){
    console->print_summary(test_suites);
}

}