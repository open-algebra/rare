if (NOT DEFINED target_file_dir OR target_file_dir STREQUAL "")
    message(FATAL_ERROR "target_file_dir is required")
endif ()

if (NOT DEFINED target_runtime_dlls OR target_runtime_dlls STREQUAL "")
    message(STATUS "No runtime DLLs to copy.")
    return()
endif ()

# Runtime DLLs are passed as a pipe-delimited string to avoid list/shell expansion issues.
string(REPLACE "|" ";" runtime_dll_list "${target_runtime_dlls}")

foreach (runtime_dll IN LISTS runtime_dll_list)
    if (runtime_dll STREQUAL "")
        continue()
    endif ()

    execute_process(
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different "${runtime_dll}" "${target_file_dir}"
        COMMAND_ERROR_IS_FATAL ANY)
endforeach ()

