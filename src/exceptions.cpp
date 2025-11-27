#include "noexct/Exceptions.h"


namespace noexct {
AssertionFailedException::AssertionFailedException(const char* msg)
: message(msg) {}


const char* AssertionFailedException::what() const noexcept{
    return message;
}
}