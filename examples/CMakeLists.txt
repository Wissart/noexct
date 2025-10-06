add_executable(example-basic basic_example.cpp)
target_link_libraries(example-basic NoExCT::NoExCT)

add_executable(example-assertions assertions_example.cpp)
target_link_libraries(example-assertions NoExCT::NoExCT)

add_executable(example-fixtures fixtures_example.cpp)
target_link_libraries(example-fixtures NoExCT::NoExCT)

add_dependencies(example-basic NoExCT)
add_dependencies(example-assertions NoExCT) 
add_dependencies(example-fixtures NoExCT)

# Copy DLL fow Windows
if(WIN32 AND NOEXCT_BUILD_SHARED_LIBS)
    add_custom_command(TARGET example-basic POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:NoExCT>
        $<TARGET_FILE_DIR:example-basic>
    )
    add_custom_command(TARGET example-assertions POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:NoExCT>
        $<TARGET_FILE_DIR:example-assertions>
    )
    add_custom_command(TARGET example-fixtures POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:NoExCT>
        $<TARGET_FILE_DIR:example-fixtures>
    )
endif()

message(STATUS "NoExCT create examples")