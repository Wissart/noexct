#pragma once

#include <memory>

#include "ITestReporter.h"
#include "noexct_export.h"


namespace noexct {


class NOEXCT_API ITestRunner {
public:
    virtual ~ITestRunner() = default;

    template<typename ReporterType>
    void set_reporter(){
        static_assert(std::is_base_of<ITestReporter, ReporterType>::value,
                        "ReporterType must be derived from IReporter");
        set_reporter(std::make_shared<ReporterType>());
    }
    virtual void set_reporter(std::shared_ptr<ITestReporter> reporter) = 0;
    virtual void run_all() = 0;
};

}