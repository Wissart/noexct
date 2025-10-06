#pragma once

#include <string>
#include <functional>



namespace noexct{
    
class TestCase{
private:
    std::string name;
    std::function<void()> test_func;
    bool passed;
    double duration;
    std::string error_message;
public:
    TestCase(const std::string& name, std::function<void()> test_func);

    const std::string& get_name() const;
    bool is_passed() const;
    double get_duration() const;
    const std::string& get_error_message() const;

    void run();
};

}