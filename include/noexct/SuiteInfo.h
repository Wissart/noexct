#pragma once

#include <string>
#include <memory>

namespace noexct{
class SuiteInfo{
public:
    ~SuiteInfo() = default;

    const std::string& get_name() const {
        return name;
    }

    virtual size_t get_passed_count() const = 0;
    virtual size_t get_failed_count() const = 0;
protected:
    explicit SuiteInfo(const std::string& name) 
                : name(name) {}

    std::string name;
};

}