# =============================================================================
# MSVC SETTINGS
# =============================================================================

message(STATUS "Applying MSVC compiler settings")


#Warning flags
add_compile_options(
    /W4
    /permissive-
)

#Config Flags
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(
        /Zi
        /Od
        /Ob0
        /RTC1
        /MDd
    )
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_options(
        /O2
        /Ob2
        /Ot
        /DNDEBUG
        /GL
        /MD
    )
    add_link_options(
        /LTCG
    )
endif()

add_compile_options(
    /Zc:__cplusplus
    /Zc:inline
)