#include "./obstacle.h"
#include "game.h"
#include "utils.h"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <stdio.h>

Obstacle *generate_obstacles(int screen_width, int screen_height) {
    Obstacle *obstacles = (Obstacle *) malloc(sizeof(Obstacle) * OBSTACLE_COUNT);
    if (obstacles == NULL) {
        fprintf(stderr, "Error allocation space for obstacles");
    }
    int width = 30;
    int height = 20;
    int gap = 5;
    int row = 1;
    int count = 0;

    for (int i = 0; i < OBSTACLE_COUNT; i++) {
        (obstacles + i)->w = width;
        (obstacles + i)->h = height;
        (obstacles + i)->show = true;
        (obstacles + i)->color = (SDL_Color) { 
            .r = 0x00, .g = 0xFF, .b = 0x00, .a = 0xFF 
        };

        int pos_x = (width + gap) * count;
        if (pos_x >= screen_width) {
            pos_x = 0;
            count = 0;
            row++;
        }
        int pos_y = (height + gap) * row;
        (obstacles + i)->position = (Vec2) {
            .x = (float) pos_x,
            .y = (float) pos_y 
        };
        count++;
    }
    return obstacles;
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

