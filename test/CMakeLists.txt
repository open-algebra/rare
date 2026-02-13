add_executable(RARETests)

target_sources(RARETests PRIVATE
    RARETest.cpp)

target_build_strict(RARETests)
target_link_libraries(RARETests PRIVATE RARE Catch2::Catch2WithMain)

if (NOT Catch2_FOUND)
    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
endif ()

include(CTest)
include(Catch)

catch_discover_tests(RARETests)