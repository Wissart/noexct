# =============================================================================
# PROJECT SETTINGS
# =============================================================================


if(NOT SETTINGS_LOADED)
    set(SETTINGS_LOADED ON)

    message(STATUS "===Loading settings for ${PROJECT_NAME}===")

    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)

    if(POLICY CMP0077)
        cmake_policy(SET CMP0077 NEW)
    endif()

    # Platform Settings
    if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
        include(platforms/WindowsSettings)
        message(STATUS "Platform: Windows")
    else()
        message(STATUS "Undefined Platform: ${CMAKE_SYSTEM_NAME}")
    endif()

    #Compiler flags
    if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        include(compilers/MSVCFlags)
        message(STATUS "Compiler: MSVC ${CMAKE_CXX_COMPILER_VERSION}")
    else()
        message(STATUS "Undefined Compiler: ${CMAKE_COMPILER_ID")
    endif()
endif()