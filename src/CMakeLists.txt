add_library(RARE)

target_sources(RARE PUBLIC
        FILE_SET rare_sources
        TYPE CXX_MODULES
        FILES
        RARE.cppm)

target_compile_features(RARE PUBLIC cxx_std_23)
target_link_libraries(RARE PUBLIC Oasis::Oasis SDL3_ttf::SDL3_ttf)
target_build_strict(RARE)