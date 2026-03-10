//
// Created by Matthew McCall on 2/3/26.
//
#include <print>

#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>

import rare.core;

extern "C" {
auto SDL_AppInit(void**, int, char**) -> SDL_AppResult;
auto SDL_AppIterate(void*) -> SDL_AppResult;
auto SDL_AppEvent(void*, SDL_Event* event) -> SDL_AppResult;
auto SDL_AppQuit(void*, SDL_AppResult) -> void;
}

struct AppState {
    SDL_Window* window;
    SDL_Renderer* renderer;
};

auto SDL_AppInit(void** appstate, int, char**) -> SDL_AppResult
{
    std::print("Hello, World!");

    if (not SDL_Init(SDL_INIT_VIDEO)) {
        std::print("Failed to initialize SDL: {}", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    if (not SDL_CreateWindowAndRenderer("RARE Sample", 800, 600, SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY, &window, &renderer)) {
        std::print("Failed to create window and/or renderer: {}", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    *appstate = new AppState { window, renderer };
    return SDL_APP_CONTINUE;
}

auto SDL_AppIterate(void* appstate) -> SDL_AppResult
{
    auto& [window, renderer] = *static_cast<AppState*>(appstate);
    SDL_SetRenderDrawColorFloat(renderer, 1.0f, 0.0f, 0.0f, 1.0f);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    return SDL_APP_CONTINUE;
}

auto SDL_AppEvent(void*, SDL_Event* event) -> SDL_AppResult
{
    switch (event->type) {
    case SDL_EVENT_QUIT:
        return SDL_APP_SUCCESS;
    default:
    }

    return SDL_APP_CONTINUE;
}

auto SDL_AppQuit(void* appstate, SDL_AppResult) -> void
{
    const auto& [window, renderer] = *static_cast<AppState*>(appstate);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}
