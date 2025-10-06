#pragma once
#include "noexct_export.h"



namespace noexct{
class TestFixture {
public:
    virtual ~TestFixture() = default;

    virtual void setup() = 0;
    virtual void teardown() = 0;
};
}