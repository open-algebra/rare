function (target_build_strict TARGET_NAME)
    if (RARE_BUILD_STRICT)
        target_compile_options(${TARGET_NAME} PRIVATE
                $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
                $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
        )
    endif ()
endfunction()