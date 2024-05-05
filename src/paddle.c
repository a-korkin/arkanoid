#include <stdio.h>
#include "./paddle.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>

void update_paddle(float delta_time) {

}

void render_paddle(SDL_Renderer *renderer, Paddle *paddle) {
    int success = SDL_SetRenderDrawColor(
            renderer, 
            paddle->color.r, 
            paddle->color.g, 
            paddle->color.b, 
            paddle->color.a);
    if (success != 0) {
        fprintf(stderr, "Error set draw color paddle: %s", SDL_GetError());
    }
    SDL_Rect rect = { 
        .x = paddle->position.x, 
        .y = paddle->position.y,
        .w = paddle->w,
        .h = paddle->h,
    };
    success = SDL_RenderFillRect(renderer, &rect);
    if (success != 0) {
        fprintf(stderr, "Error draw paddle: %s", SDL_GetError());
    }
}

