#pragma once




namespace noexct{
class Test{
public:
    virtual ~Test() = default;

    virtual void suite_setup() {};
    virtual void suite_teardown() {}; 

    virtual void setup() {};
    virtual void teardown() {};
};
}