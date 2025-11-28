#pragma once

#include "TestManager.h"
#include "macroses/registration.h"
#include "macroses/assertions.h"
#include "noexct_export.h"


#define RUN_ALL_TESTS() \
    noexct::TestManager::instance().run_all_tests();
