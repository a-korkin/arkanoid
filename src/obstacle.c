#include "./obstacle.h"
#include "utils.h"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <stdio.h>

Obstacle *create_obstacle(int w, int h) {
    Obstacle *obstacle = (Obstacle *) malloc(sizeof(Obstacle));
    if (obstacle == NULL) {
        fprintf(stderr, "Error allocation space for obstacle");
    }
    obstacle->w = 30;
    obstacle->h = 10;
    obstacle->show = true;
    obstacle->color = (SDL_Color) { .r = 0x00, .g = 0xFF, .b = 0x00, .a = 0xFF };
    obstacle->position = (Vec2) { .x = 50.0f, .y = 50.0f };

    return obstacle;
}

void update_obstacle(Obstacle *obstacle, int w, int h, float delta_time) {}

void render_obstacle(SDL_Renderer *renderer, Obstacle *obstacle) {
    SDL_FRect rect = (SDL_FRect) { 
        .x = obstacle->position.x, 
        .y = obstacle->position.y, 
        .w = obstacle->w,
        .h = obstacle->h
    };

    SDL_SetRenderDrawColor(renderer, 
            obstacle->color.r, obstacle->color.g, 
            obstacle->color.b, obstacle->color.a);
    SDL_RenderFillRectF(renderer, &rect);
}

