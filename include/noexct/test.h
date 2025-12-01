#pragma once



namespace noexct{
class SuiteFixture{
public:
    virtual ~SuiteFixture() = default;
    virtual void suite_setup() {};
    virtual void suite_teardown() {};
};
class Test : public SuiteFixture{
public:
    virtual void setup() {};
    virtual void teardown() {};
};
}