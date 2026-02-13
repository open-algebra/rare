//
// Created by Matthew McCall on 2/3/26.
//
module;

#include <string>
#include <print>

export module rare.core;

namespace rare
{
   export auto hello() -> std::string
   {
      return "Hello, World!";
   }
}