cmake_minimum_required(VERSION 3.15)
project(NoExCT VERSION 1.0.0 LANGUAGES CXX)

# =============================================================================
# Configuration Options
# =============================================================================
option(NOEXCT_BUILD_SHARED_LIBS "Build NoExCT as shared library" OFF)
option(NOEXCT_BUILD_EXAMPLES "Build NoExCT examples" OFF)
option(NOEXCT_INSTALL "Enable NoExCT installation" ON)

#These commands run if this is main project
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

    #Setup project settings
    include(ProjectSettings)
endif()

# =============================================================================
# Components
# =============================================================================

# Main source
add_subdirectory(src)

# Examples
if(NOEXCT_BUILD_EXAMPLES)
    add_subdirectory(docs/examples)
endif()

# =============================================================================
# Installation and Package Configuration
# =============================================================================
if(NOEXCT_INSTALL)
    # Installation
    include(GNUInstallDirs)

    install(
        TARGETS NoExCT
        EXPORT NoExCTTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} 
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )

    install(
        DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING PATTERN "*.h"
    )

    install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/src/noexct_export.h
        DESTINATION ${INCLUDE_INSTALL_DIR}/${PROJECT_NAME}
    )
    
    install(
        EXPORT NoExCTTargets
        FILE NoExCTTargets.cmake
        NAMESPACE NoExCT::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/NoExCT
    )

    # Package Configuration
    include(CMakePackageConfigHelpers)

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
endif()
