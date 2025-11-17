#pragma once

#include "test_fixture.h"
#include "test_case.h"
#include "test_suite.h"
#include "test_manager.h"
#include "assertions.h"
#include "reporter.h"
#include "reporters/console_reporter.h"
#include "runner.h"
#include "noexct_export.h"



namespace noexct {
    NOEXCT_API int run_all_tests();
}

#define RUN_ALL_TESTS() \
    noexct::run_all_tests();
