//
// Created by Matthew McCall on 2/3/26.
//
module;

#include <print>
#include <string>

#include "SDL3_ttf/SDL_ttf.h"
#include "Oasis/Expression.hpp"

export module rare.core;

namespace rare {
export auto hello() -> std::string
{
    return "Hello, World!";
}

export auto RenderToTexture(const Oasis::Expression&, SDL_Surface*) -> SDL_Texture*
{
    return nullptr;
}

}