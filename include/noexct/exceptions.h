#pragma once

#include <string>
#include <sstream>
#include "noexct_export.h"


namespace noexct {

class NOEXCT_API AssertionFailedException{
private:
    const char* message;
public:
    explicit AssertionFailedException(const char* msg);

    AssertionFailedException(const AssertionFailedException&) = default;
    AssertionFailedException(AssertionFailedException&&) noexcept = default;
    AssertionFailedException& operator=(const AssertionFailedException&) = default;
    AssertionFailedException& operator=(AssertionFailedException&&) noexcept = default;

    virtual ~AssertionFailedException() = default;
    
    const virtual char* what() const noexcept;
};
}