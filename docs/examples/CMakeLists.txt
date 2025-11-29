add_executable(example-basic basic-example.cpp)
target_link_libraries(example-basic NoExCT::NoExCT)

add_executable(example-assertions assertions-example.cpp)
target_link_libraries(example-assertions NoExCT::NoExCT)

add_executable(example-fixtures fixtures-example.cpp)
target_link_libraries(example-fixtures NoExCT::NoExCT)

add_dependencies(example-basic NoExCT)
add_dependencies(example-assertions NoExCT) 
add_dependencies(example-fixtures NoExCT)

include(UtilityFunc)
# Copy DLL fow Windows
if(WIN32 AND NOEXCT_BUILD_SHARED_LIBS)
    copy_shared_lib_for(example-assertions)
endif()

message(STATUS "NoExCT create examples")