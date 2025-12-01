#pragma once

#include <string>
#include <exception>
#include <sstream>
#include "noexct_export.h"


namespace noexct {

class NOEXCT_API AssertionFailedException : public std::exception {
private:
    std::string message;
public:
    explicit AssertionFailedException(const std::string& msg);
    virtual ~AssertionFailedException() = default;

    AssertionFailedException(const AssertionFailedException&) = default;
    AssertionFailedException(AssertionFailedException&&) noexcept = default;
    AssertionFailedException& operator=(const AssertionFailedException&) = default;
    AssertionFailedException& operator=(AssertionFailedException&&) noexcept = default;

    
    const char* what() const noexcept override;
};
}