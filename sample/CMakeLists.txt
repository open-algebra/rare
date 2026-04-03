add_executable(RARESample MACOSX_BUNDLE)

target_sources(RARESample PRIVATE
        main.cpp
)

target_link_libraries(RARESample PRIVATE RARE SDL3::SDL3 spdlog::spdlog)
target_build_strict(RARESample)
target_copy_vendored_deps(RARESample)
target_package_resources(RARESample "${CMAKE_CURRENT_SOURCE_DIR}/assets")