//
// Created by Matthew McCall on 2/3/26.
//
#include <catch2/catch_test_macros.hpp>

import RARE.Core;

TEST_CASE("Basic test")
{
    REQUIRE(rare::hello() == "Hello, World!");
}