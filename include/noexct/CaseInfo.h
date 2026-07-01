#pragma once

#include <string>


namespace noexct{
class CaseInfo{
public:
    virtual ~CaseInfo() = default;

    const std::string& get_name() const { return name; }
    bool is_passed() const { return passed; }
    double get_duration() const { return duration; }
    const std::string& get_error_message() const { return error_message; }
protected:
    explicit CaseInfo(const std::string name)
                : name(name),
                  passed(false),
                  duration(0),
                  error_message("") {}
                  
    std::string name;
    bool passed;
    double duration;
    std::string error_message;
};
}