#include "noexct/test-engine.h"

SUITE(ASSERTIONS_EXAMPLE)

TEST(BASE_ASSERTTIONS){
    ASSERT_EQ(2,2)
    ASSERT_NE(2,1)
    ASSERT_TRUE(true)
    ASSERT_FALSE(false)
}


int main(){
    RUN_ALL_TESTS()
}