#include <iostream>
#include "noexct/test_engine.h"

class SuiteFixture : public noexct::Test {
public:
    void suite_setup() override{
        std::cout << "SuiteFixture: setup()" << std::endl;
    }
    void suite_teardown() override{
        std::cout << "SuiteFixture: teardown()" << std::endl;
    }
    void setup() override{
        std::cout << "CaseFixture: setup()" << std::endl;
    }
    void teardown() override{
        std::cout << "CaseFixture: teardown()" << std::endl;
    }
};

class UniqCaseFixture : public noexct::Test {
public:
    void setup() override{
        std::cout << "UniqCaseFixture: setup()" << std::endl;
    }
    void teardown() override{
        std::cout << "UniqCaseFixture: teardown()" << std::endl;
    }
};



TEST_SUITE(FIXTURES_EXAMPLE)

FIXTURE(SuiteFixture)

TEST_F(UniqCaseFixture, CASE_NAME_PASS){
    ASSERT_EQ(2,2)
}

TEST_SF(CASE_NAME_FAIL){
    ASSERT_EQ(2,1)
}

int main(){
    RUN_ALL_TESTS()
}