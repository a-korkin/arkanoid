#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "utils.h"
#include <stdbool.h>
#include <SDL2/SDL.h>

typedef struct {
    int w, h;
    Vec2 position;
    bool show;
    SDL_Color color;
} Obstacle;

Obstacle *create_obstacle(int w, int h);
void update_obstacle(Obstacle *obstacle, int w, int h, float delta_time);
void render_obstacle(SDL_Renderer *renderer, Obstacle *obstacle);

#endif // OBSTACLE_H

