#pragma once




namespace noexct{
class SuiteFixture{
public:
    virtual ~SuiteFixture() = default;
    virtual void suite_setup() {};
    virtual void suite_teardown() {};
};

class CaseFixture{
public:
    virtual ~CaseFixture() = default;
    virtual void setup() {};
    virtual void teardown() {};
};

class Fixture : public SuiteFixture, public CaseFixture {
public:
    virtual ~Fixture() = default;
};
}