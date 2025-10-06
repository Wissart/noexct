#include <iostream>
#include "noexct/test_engine.h"

class SuiteFixture : public noexct::TestFixture {
public:
    void setup() override{
        std::cout << "SuiteFixture: setup()" << std::endl;
    }
    void teardown() override{
        std::cout << "SuiteFixture: teardown()" << std::endl;
    }
};
class CaseFixture : public noexct::TestFixture {
public:
    void setup() override{
        std::cout << "CaseFixture: setup()" << std::endl;
    }
    void teardown() override{
        std::cout << "CaseFixture: teardown()" << std::endl;
    }
};



TEST_SUITE(FIXTURES_EXAMPLE)

SUITE_FIXTURE(SuiteFixture) // setup fixture for current suite
CASE_FIXTURE(CaseFixture) // setup fixture for each test case in current suite

TEST_CASE(CASE_NAME_PASS){
    ASSERT_EQ(2,2)
}

TEST_CASE(CASE_NAME_FAIL){
    ASSERT_EQ(2,1)
}

int main(){
    RUN_ALL_TESTS()
}