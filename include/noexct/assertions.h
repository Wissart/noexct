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

#define ASSERT_TRUE(expr) \
    if(!(expr)) { \
        const char* message = "Assertion failed: "#expr"is not true"; \
        throw noexct::AssertionFailedException(message); \
    }

#define ASSERT_FALSE(expr) \
    if(expr) { \
        const char* message = "Assertion failed: "#expr"is true"; \
        throw noexct::AssertionFailedException(message); \
    }

#define ASSERT_EQ(a, b) \
    if((a) != (b)) { \
        const char* message = "Assertion failed: "#a" != "#b; \
        throw noexct::AssertionFailedException(message); \
    }

#define ASSERT_NE(a, b) \
    if((a) == (b)) { \
        const char* message = "Assertion failed: "#a" == "#b; \
        throw noexct::AssertionFailedException(message); \
    }

#define ASSERT_THROW(expr, exception_type) \
    try { \
        expr; \
        throw noexct::AssertionFailedException("Expected exception" #exception_type "was not thrown"); \
    } catch(const exception_type&) {\
    } catch(...) { \
        throw noexct::AssertionFailedException("Unexpected exception was thrown"); \
    }