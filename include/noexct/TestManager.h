#pragma once
#include <vector>
#include <memory>
#include <functional>

#include "Test.h"
#include "TestCase.h"
#include "ITestBuilder.h"
#include "ITestRunner.h"
#include "noexct_export.h"

namespace noexct{

class NOEXCT_API TestManager{
private:
    TestManager();
    ~TestManager();
public:
    static TestManager& instance();

    std::shared_ptr<ITestBuilder> get_builder();
    std::shared_ptr<ITestRunner> get_runner();
    void run_all_tests();

private:
    class TestManagerImpl;
    TestManagerImpl* impl;
};

}