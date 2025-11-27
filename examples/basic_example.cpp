#include "noexct/test-engine.h"

TEST_SUITE(SUITE_NAME)

TEST_CASE(CASE_NAME_PASS){
    ASSERT_EQ(2,2)
}

TEST_CASE(CASE_NAME_FAIL){
    ASSERT_EQ(2,1)
}

int main(){
    RUN_ALL_TESTS()
}