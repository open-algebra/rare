cmake_minimum_required(VERSION 3.31)
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

FetchContent_MakeAvailable(Catch2)

FetchContent_Declare(
        OASIS
        GIT_REPOSITORY https://github.com/open-algebra/Oasis.git
)

FetchContent_MakeAvailable(OASIS Catch2)

add_subdirectory(src)

if (RARE_BUILD_SAMPLE)
        add_subdirectory(sample)
endif ()

if (RARE_BUILD_TESTS)
        add_subdirectory(test)
endif ()