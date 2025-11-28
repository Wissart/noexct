#include "noexct/test-engine.h"

SUITE(SUITE_NAME)

TEST(CASE_NAME_PASS){
    ASSERT_EQ(2,2)
}

TEST(CASE_NAME_FAIL){
    ASSERT_EQ(2,1)
}

int main(){
    RUN_ALL_TESTS()
}