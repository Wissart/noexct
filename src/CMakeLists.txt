include(GNUInstallDirs) 

set(NOEXCT_SOURCES
    Exceptions.cpp
    Suite.cpp
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

include(GenerateExportHeader)
generate_export_header(NoExCT
    BASE_NAME NOEXCT
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
        ${CMAKE_CURRENT_SOURCE_DIR}/reporters
)

set_target_properties(NoExCT PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/noexct_export.h
    DESTINATION include/noexct
)

install(TARGETS NoExCT
    EXPORT NoExCTTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} 
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.h"
)

add_library(NoExCT::NoExCT ALIAS NoExCT)