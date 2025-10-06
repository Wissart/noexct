#include <chrono>

#include "noexct/assertions.h"
#include "noexct/test_case.h"


namespace noexct{

TestCase::TestCase(const std::string& name, std::function<void()> test_func) 
: name(name) , test_func(test_func), passed(false) {}


const std::string& TestCase::get_name() const { return name; }
bool TestCase::is_passed() const { return passed; }
double TestCase::get_duration() const { return duration; }
const std::string& TestCase::get_error_message() const { return error_message; }

void TestCase::run(){
    double start_time = 0;
    try{
        start_time = clock();
        test_func();
        duration = (double)(clock() - start_time)/CLOCKS_PER_SEC;
        
        passed = true;
    } catch(const AssertionFailedException& ex){
        duration = (double)(clock() - start_time)/CLOCKS_PER_SEC;
        passed = false;
        error_message = ex.what();
    }
}

}
