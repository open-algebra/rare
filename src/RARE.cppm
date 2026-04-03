//
// Created by Matthew McCall on 2/3/26.
//
module;

#include <print>
#include <string>

#include <SDL3_ttf/SDL_ttf.h>
#include <boost/leaf.hpp>
#include <gsl-lite/gsl-lite.hpp>

#include "Oasis/Expression.hpp"

export module RARE.Core;

import RARE.Types;

namespace rare {
export auto hello() -> std::string
{
    return "Hello, World!";
}

export auto RenderToTexture(const Oasis::Expression&, SDL_Texture* texture, SDL_Renderer* renderer) -> Result<gsl_lite::not_null<SDL_Texture*>>
{
    if (not TTF_Init())
        return NewError<std::string>(SDL_GetError());

    SDL_SetRenderTarget(renderer, texture);

    SDL_SetRenderDrawColorFloat(renderer, 0.0f, 1.0f, 0.0f, 1.0f);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_SetRenderTarget(renderer, nullptr);

    TTF_Quit();
    return gsl_lite::make_not_null(texture);
}

}