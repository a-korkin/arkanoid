#ifndef PADDLE_H
#define PADDLE_H

#include "./utils.h"
#include <SDL2/SDL.h>

typedef struct {
    int w, h;
    Vec2 position;
    Color color;
} Paddle;

void update_paddle(float delta_time);
void render_paddle(SDL_Renderer *renderer, Paddle *paddle);

#endif //PADDLE_H

