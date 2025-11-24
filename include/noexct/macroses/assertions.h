#define ASSERT_TRUE(expr) \
    do{\
        if(!(expr)) { \
            const char* message = "Assertion failed: "#expr"is not true"; \
            throw noexct::AssertionFailedException(message); \
        } \
    }while(0);

#define ASSERT_FALSE(expr) \
    do{ \
        if(expr) { \
            const char* message = "Assertion failed: "#expr"is true"; \
            throw noexct::AssertionFailedException(message); \
        } \
    }while(0);

#define ASSERT_EQ(a, b) \
    do{ \
        auto _temp_a = (a); \
        auto _temp_b = (b); \
        if(_temp_a != _temp_b) { \
            const char* message = "Assertion failed: "#a" != "#b; \
            throw noexct::AssertionFailedException(message); \
        } \
    }while(0);

#define ASSERT_NE(a, b) \
    do{ \
        auto _temp_a = (a); \
        auto _temp_b = (b); \
        if(_temp_a == _temp_b) { \
            const char* message = "Assertion failed: "#a" == "#b; \
            throw noexct::AssertionFailedException(message); \
        } \
    }while(0);

#define ASSERT_THROW(expr, exception_type) \
    try { \
        expr; \
        throw noexct::AssertionFailedException("Expected exception" #exception_type "was not thrown"); \
    } catch(const exception_type&) {\
    } catch(...) { \
        throw noexct::AssertionFailedException("Unexpected exception was thrown"); \
    }