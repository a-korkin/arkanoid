#include <stdio.h>
#include "./paddle.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>

void create_paddle(Paddle *paddle, int w, int h) {
    paddle->w = 100;
    paddle->h = 10;
    paddle->position.x = w / 2;
    paddle->position.y = h - 20;
    paddle->color.r = 0x00;
    paddle->color.g = 0x00;
    paddle->color.b = 0xFF;
    paddle->color.a = 0xFF;
}

void update_paddle(Paddle *paddle, int w) {
    if (paddle->position.x <= 0) {
        paddle->position.x = 0;
    }
    if (paddle->position.x + paddle->w >= w) {
        paddle->position.x = w - paddle->w;
    }
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

