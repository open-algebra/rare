//
// Created by Matthew McCall on 2/3/26.
//
module;

#include <print>
#include <string>

export module rare.core;

namespace rare {
export auto hello() -> std::string
{
    return "Hello, World!";
}
}