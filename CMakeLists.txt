cmake_minimum_required(VERSION 3.15)
project(NoExCT VERSION 1.0.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(NOEXCT_BUILD_EXAMPLES "Build NoExCT examples" OFF)
option(NOEXCT_BUILD_SHARED_LIBS "Build NoExCT as shared library" OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(CompilerFlags)
if(MSVC)
    include(MSVCSettings)
elseif(UNIX AND NOT APPLE)
    include(LinuxSettings)
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
