cmake_minimum_required(VERSION 3.15)
project(NoExCT VERSION 1.0.0 LANGUAGES CXX)

option(NOEXCT_BUILD_EXAMPLES "Build NoExCT examples" OFF)
option(NOEXCT_BUILD_SHARED_LIBS "Build NoExCT as shared library" OFF)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    message("Build Standalone")
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
    include(ProjectSettings)
else()
    message("${CMAKE_PROJECTNAME} not equal ${PROJECT_NAME}")
endif()

add_subdirectory(src)

if(NOEXCT_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()


include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(
    EXPORT NoExCTTargets
    FILE NoExCTTargets.cmake
    NAMESPACE NoExCT::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/NoExCT
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/NoExCTConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/NoExCTConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/NoExCTConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/NoExCT
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/NoExCTConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/NoExCTConfigVersion.cmake
    DESTINATION
        ${CMAKE_INSTALL_LIBDIR}/cmake/NoExCT
)
