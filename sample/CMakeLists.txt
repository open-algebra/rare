add_executable(RARESample MACOSX_BUNDLE)

target_sources(RARESample PRIVATE
    main.cpp
)

target_link_libraries(RARESample PRIVATE RARE SDL3::SDL3)
target_build_strict(RARESample)