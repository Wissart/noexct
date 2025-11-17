#include "noexct/test_engine.h"

namespace noexct {

int run_all_tests(){
    Runner runner(TestManager::instance().get_suites());
    runner.set_reporter(std::make_shared<ConsoleReporter>());
    runner.run_all();
    return 0;
}

}