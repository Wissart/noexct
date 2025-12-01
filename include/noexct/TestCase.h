#pragma once

#include <string>
#include <functional>
#include <chrono>

#include "TestExceptions.h"
#include "CaseInfo.h"

namespace noexct{

class TestCase : public CaseInfo{
public:
    virtual void run() = 0;
protected:
    explicit TestCase(const std::string name)
                : CaseInfo(name) {}
};

template<typename TestType>
class TypedTestCase : public TestCase{
public:
    using TestMethod = void (TestType::*)();

    TypedTestCase(const std::string& name, TestMethod method) 
    : TestCase(name), test_method(method){}

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
    TestMethod test_method;
};

}