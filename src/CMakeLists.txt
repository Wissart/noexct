 set(NOEXCT_SOURCES
    TestExceptions.cpp
    TestSuite.cpp
    TestBuilder.cpp
    TestCollection.cpp
    TestManager.cpp
    TestRunner.cpp
    reporters/ConsoleReporter.cpp
)

if(NOEXCT_BUILD_SHARED_LIBS)
    add_library(NoExCT SHARED ${NOEXCT_SOURCES})
else()
    add_library(NoExCT STATIC ${NOEXCT_SOURCES})
endif()

add_library(NoExCT::NoExCT ALIAS NoExCT)

include(GenerateExportHeader)
generate_export_header(NoExCT
    BASE_NAME NoExCT
    EXPORT_MACRO_NAME NOEXCT_API
    EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/noexct_export.h
)

target_include_directories(NoExCT
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(NoExCT PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)
