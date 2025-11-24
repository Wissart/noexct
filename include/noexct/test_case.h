#pragma once

#include <string>
#include <functional>
#include <chrono>

#include "exceptions.h"

namespace noexct{

class ITestCase{
public:
    virtual ~ITestCase() = default;

    virtual const std::string& get_name() const = 0;
    virtual bool is_passed() const = 0;
    virtual double get_duration() const = 0;
    virtual const std::string& get_error_message() const = 0;

    virtual void run() = 0;

};

template<typename TestType>
class TestCase : public ITestCase{
public:
    using TestMethod = void (TestType::*)();

    TestCase(const std::string& name, TestMethod method) 
    : name(name) , test_method(method), passed(false) {}


    const std::string& get_name() const override { return name; }
    bool is_passed() const override { return passed; }
    double get_duration() const override { return duration; }
    const std::string& get_error_message() const override { return error_message; }

    void run() override {
        double start_time = 0;
        try{
            auto test = std::make_unique<TestType>();
            test->setup();
            start_time = clock();
            (test.get()->*test_method)();
            duration = (double)(clock() - start_time)/CLOCKS_PER_SEC;
            test->teardown();
            passed = true;
        } 
        catch(const AssertionFailedException& ex){
            duration = (double)(clock() - start_time)/CLOCKS_PER_SEC;
            passed = false;
            error_message = ex.what();
        }
    }
private:
    std::string name;
    TestMethod test_method;
    bool passed;
    double duration;
    std::string error_message;
};

}