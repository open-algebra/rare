cmake_minimum_required(VERSION 3.30)
project(rare)

option(RARE_BUILD_SAMPLE "Builds the sample application" OFF)
option(RARE_BUILD_TESTS "Builds the test cases" ON)
option(RARE_BUILD_STRICT "Compiles with all compiler warnings, and warnings as errors" ON)

include(cmake/BuildStrict.cmake)
include(cmake/AppPackageResources.cmake)
include(FetchContent)

include(cmake/FetchBoost.cmake)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY "https://github.com/catchorg/Catch2.git"
        GIT_TAG v3.12.0
        EXCLUDE_FROM_ALL
        FIND_PACKAGE_ARGS CONFIG
)

FetchContent_Declare(
        GSL
        GIT_REPOSITORY "https://github.com/gsl-lite/gsl-lite.git"
        GIT_TAG v1.1.0
        EXCLUDE_FROM_ALL
        FIND_PACKAGE_ARGS CONFIG
)

FetchContent_Declare(
        SDL3
        GIT_REPOSITORY "https://github.com/libsdl-org/SDL.git"
        GIT_TAG release-3.4.2
        EXCLUDE_FROM_ALL
        FIND_PACKAGE_ARGS CONFIG
)

FetchContent_Declare(
        SDL3_ttf
        GIT_REPOSITORY "https://github.com/libsdl-org/SDL_ttf.git"
        GIT_TAG release-3.2.2
        EXCLUDE_FROM_ALL
        FIND_PACKAGE_ARGS CONFIG
)

FetchContent_Declare(
        OASIS
        GIT_REPOSITORY "https://github.com/open-algebra/Oasis.git"
        GIT_TAG master
        EXCLUDE_FROM_ALL
)

FetchContent_MakeAvailable(Catch2 GSL SDL3 SDL3_ttf)
set(BUILD_SHARED_LIBS OFF)
FetchContent_MakeAvailable(OASIS)

add_subdirectory(src)

if (RARE_BUILD_SAMPLE)
        FetchContent_Declare(
                spdlog
                GIT_REPOSITORY https://github.com/gabime/spdlog.git
                GIT_TAG v1.17.0
                EXCLUDE_FROM_ALL
                FIND_PACKAGE_ARGS CONFIG
        )

        FetchContent_MakeAvailable(spdlog)

        add_subdirectory(sample)
endif ()

if (RARE_BUILD_TESTS)
        add_subdirectory(test)
endif ()