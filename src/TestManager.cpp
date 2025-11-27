#include <memory>

#include "noexct/TestManager.h"
#include "reporters/ConsoleReporter.h"
#include "TestCollection.h"
#include "TestBuilder.h"
#include "TestRunner.h"


namespace noexct{

class TestManager::TestManagerImpl{
public:
    TestManagerImpl(std::shared_ptr<TestCollection> test_collection)
    : builder(std::make_shared<TestBuilder>(test_collection)),
      runner(std::make_shared<TestRunner>(test_collection)) {}

    std::shared_ptr<TestBuilder> get_builder() { return builder; }
    std::shared_ptr<ITestRunner> get_runner() { return runner; }

    void run_all_tests(){
        if(!runner->get_reporter())
            runner->set_reporter<ConsoleReporter>();
        
        runner->run_all();
    }
private:
    std::shared_ptr<TestBuilder> builder;
    std::shared_ptr<TestRunner> runner;
};

TestManager::TestManager()
: impl(new TestManagerImpl(std::make_shared<TestCollection>())) {}

TestManager::~TestManager(){
    delete impl;
}

TestManager& TestManager::instance(){
    static TestManager manager;
    return manager;
}

std::shared_ptr<ITestBuilder> TestManager::get_builder() { return impl->get_builder(); }
std::shared_ptr<ITestRunner> TestManager::get_runner() { return impl->get_runner(); }

void TestManager::run_all_tests(){
    impl->run_all_tests();
}
}