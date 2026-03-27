if (WIN32 AND TARGET Oasis::Oasis)
    get_target_property(_oasis_type Oasis::Oasis TYPE)

    if (_oasis_type STREQUAL "SHARED_LIBRARY")
        add_library(RARE SHARED)
    elseif (_oasis_type STREQUAL "STATIC_LIBRARY")
        add_library(RARE STATIC)
    else ()
        add_library(RARE)
    endif ()
else ()
    add_library(RARE)
endif ()

target_sources(RARE PUBLIC
        FILE_SET rare_sources
        TYPE CXX_MODULES
        FILES
        RARE.cppm
        Types.cppm)

target_compile_features(RARE PUBLIC cxx_std_23)
target_link_libraries(RARE PUBLIC Oasis::Oasis SDL3_ttf::SDL3_ttf)
target_build_strict(RARE)