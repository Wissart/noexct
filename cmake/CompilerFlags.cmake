function(set_common_compiler_flags target)
    target_compile_features(${target} PUBLIC cxx_std_17)

    if(MSVC)
        #MSVC flags
        target_compile_options(${target} PRIVATE
            /W4
            /WX
            /permissive-
            /Zc:__cplusplus
        )
    
    else()
        #GCC/Clang flags
    endif()
endfunction()
