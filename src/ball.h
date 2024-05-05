#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>
#include "./utils.h"

typedef struct {
    int size;
    Vec2 position;
    Color color;
} Ball;

void create_ball(Ball *ball, int w, int h);
void update_ball(Ball *ball);
void render_ball(SDL_Renderer *renderer, Ball *ball);

#endif //BALL_H
       
