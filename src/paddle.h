#ifndef PADDLE_H
#define PADDLE_H

#include "./utils.h"
#include <SDL2/SDL.h>

#define PADDLE_STEP 30

typedef struct {
    int w, h;
    Vec2 position;
    Color color;
} Paddle;

void create_paddle(Paddle *paddle, int w, int h);
void update_paddle(Paddle *paddle, int w);
void render_paddle(SDL_Renderer *renderer, Paddle *paddle);

#endif //PADDLE_H

