message(STATUS "Configuring for MSVC compiler")

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
message(STATUS "MSVC runtime library: ${CMAKE_MSVC_RUNTIME_LIBRARY}")


if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Debug build configuration")
else()
    message(STATUS "Release build configuration")
endif()