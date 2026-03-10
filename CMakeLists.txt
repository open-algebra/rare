cmake_minimum_required(VERSION 3.30)
project(rare)

option(RARE_BUILD_SAMPLE "Builds the sample application" OFF)
option(RARE_BUILD_TESTS "Builds the test cases" ON)
option(RARE_BUILD_STRICT "Compiles with all compiler warnings, and warnings as errors" ON)

include(cmake/BuildStrict.cmake)
include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.8.0
        FIND_PACKAGE_ARGS
)

FetchContent_Declare(
        SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-3.4.2
        FIND_PACKAGE_ARGS
)

FetchContent_Declare(
        SDL3_ttf
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf.git
        GIT_TAG release-3.2.2
        FIND_PACKAGE_ARGS
)

FetchContent_Declare(
        OASIS
        GIT_REPOSITORY https://github.com/open-algebra/Oasis.git
)

FetchContent_MakeAvailable(Catch2 SDL3 SDL3_ttf OASIS)

include(cmake/FetchBoost.cmake)

add_subdirectory(src)

if (RARE_BUILD_SAMPLE)
        add_subdirectory(sample)
endif ()

if (RARE_BUILD_TESTS)
        add_subdirectory(test)
endif ()