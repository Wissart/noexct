#include <iostream>
#include <string>
#include <sstream>

#ifdef _WIN32
    #include <windows.h>
#endif

#include "ConsoleReporter.h"

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
    void print_test_start(const std::shared_ptr<CaseInfo>){
        return;
    }
    void print_test_result(const std::shared_ptr<CaseInfo> case_info){

        if(case_info->is_passed()){
            SET_COLOR(GREEN);
            std::cout << "PASS";
            SET_COLOR(RESET);
            std::cout << ": " << case_info->get_name() << "(" << case_info->get_duration() << "ms)" << "\n";
        }
        else{
            SET_COLOR(RED);
            std::cout << "FAIL";
            SET_COLOR(RESET);
            std::cout << ": " << case_info->get_name() << "(" << case_info->get_duration() << "ms)" << " - " << case_info->get_error_message() << "\n";
        }
    }
    void print_suite_start(const std::shared_ptr<SuiteInfo> suite_info){
        std::string message;

        message = "Running test suite: " + suite_info->get_name() + "\n";
        print(message);
    }
    void print_suite_result(const std::shared_ptr<SuiteInfo>){
        return;
    }
    void print_summary(const summary_report& summary){
        printL(" ");
        printL("--- SUMMARY ---");
        
        std::stringstream message;
        message << "Suites: " << summary.suite_count << ", Testes: " << summary.test_count << ", Passed: " << summary.passed_count << ", Failed: " << summary.failed_count << "\n";
        message << "Total time: (" << summary.total_time << "ms)"<< "\n";

        print(message.str());
    }
};

ConsoleReporter::ConsoleReporter() : console(std::make_unique<ConsoleWorker>()){}
ConsoleReporter::~ConsoleReporter() = default;

void ConsoleReporter::report_test_start(const std::shared_ptr<CaseInfo> case_info){
    console->print_test_start(case_info);
}
void ConsoleReporter::report_test_result(const std::shared_ptr<CaseInfo> case_info){
    console->print_test_result(case_info);
}
void ConsoleReporter::report_suite_start(const std::shared_ptr<SuiteInfo> suite_info){
    console->print_suite_start(suite_info);
}
void ConsoleReporter::report_suite_result(const std::shared_ptr<SuiteInfo> suite_info){
    console->print_suite_result(suite_info);
}

void ConsoleReporter::report_summary(const summary_report& summary){
    console->print_summary(summary);
}

}