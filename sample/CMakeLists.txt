add_executable(RARESample MACOSX_BUNDLE)

target_sources(RARESample PRIVATE
    main.cpp
)

target_link_libraries(RARESample PRIVATE RARE)
target_build_strict(RARESample)