function(target_copy_vendored_deps target_name)
    if (NOT TARGET "${target_name}")
        message(FATAL_ERROR "target_copy_vendored_deps: '${target_name}' is not a target")
    endif ()

    # Runtime DLL copying is only required on Windows.
    if (NOT WIN32)
        return()
    endif ()

    get_target_property(target_type "${target_name}" TYPE)
    if (NOT target_type STREQUAL "EXECUTABLE")
        message(FATAL_ERROR "target_copy_vendored_deps: '${target_name}' must be an executable target")
    endif ()

    set(_copy_runtime_dlls_script "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/CopyRuntimeDlls.cmake")

    add_custom_command(TARGET "${target_name}" POST_BUILD
        COMMAND "${CMAKE_COMMAND}"
            "-Dtarget_runtime_dlls=$<JOIN:$<TARGET_RUNTIME_DLLS:${target_name}>,|>"
            "-Dtarget_file_dir=$<TARGET_FILE_DIR:${target_name}>"
            "-P" "${_copy_runtime_dlls_script}"
        VERBATIM)
endfunction()
