add_executable(RARETests)

target_sources(RARETests PRIVATE
    RARETest.cpp)

target_build_strict(RARETests)
target_link_libraries(RARETests PRIVATE RARE Catch2::Catch2WithMain)

if (DEFINED catch2_SOURCE_DIR) # Only defined if obtained via FetchContent and not find_package
    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
endif ()

add_custom_command(TARGET RARETests POST_BUILD
  COMMAND_EXPAND_LISTS
  COMMAND $<IF:$<BOOL:$<TARGET_RUNTIME_DLLS:RARETests>>,
    ${CMAKE_COMMAND} -E copy_if_different $<TARGET_RUNTIME_DLLS:RARETests> $<TARGET_FILE_DIR:RARETests>,
    ${CMAKE_COMMAND} -E echo "No runtime DLLs to copy.">)

include(CTest)
include(Catch)

catch_discover_tests(RARETests)