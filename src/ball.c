#include <stdio.h>
#include "./ball.h"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>

void create_ball(Ball *ball, int w, int h) {
    ball->size = 10;
    ball->position.x = (float) w / 2 - (float) ball->size / 2;
    ball->position.y = h - 30;
    ball->color.r = 0xFF;
    ball->color.g = 0x00;
    ball->color.b = 0x00;
    ball->color.a = 0xFF;
}
void update_ball(Ball *ball, int w, int h, float delta_time) {
    ball->position.x += BALL_SPEED * ball->direction.x * delta_time;
    ball->position.y += BALL_SPEED * ball->direction.y * delta_time;
    if (ball->position.x + ball->size >= w) {
        ball->direction.x = -1;
    }
    if (ball->position.x <= 0) {
        ball->direction.x = 1;
    }
    if (ball->position.y + ball->size >= h) {
        ball->direction.y = -1;
    }
    if (ball->position.y <= 0) {
        ball->direction.y = 1;
    }
}

void render_ball(SDL_Renderer *renderer, Ball *ball) {
    int result = SDL_SetRenderDrawColor(
            renderer, 
            ball->color.r, 
            ball->color.g, 
            ball->color.b, 
            ball->color.a);
    if (result != 0) {
        fprintf(stderr, "Error set draw color ball: %s", SDL_GetError());
    }

    SDL_FRect rect = { 
        .x = ball->position.x, 
        .y = ball->position.y,
        .w = ball->size,
        .h = ball->size,
    };
    result = SDL_RenderFillRectF(renderer, &rect);
    if (result != 0) {
        fprintf(stderr, "Error draw paddle: %s", SDL_GetError());
    }
}

