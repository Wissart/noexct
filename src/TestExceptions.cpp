#include "noexct/TestExceptions.h"


namespace noexct {
AssertionFailedException::AssertionFailedException(const std::string& msg)
: message(msg) {}

const char* AssertionFailedException::what() const noexcept{
    return message.c_str();
}
}