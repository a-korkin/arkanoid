#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>
#include <stdbool.h>
#include "./game.h"
#include "./paddle.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_events.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
bool running = false;
int last_frame_time = 0;
Paddle paddle;

void init(void) {
    running = true;
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Error SDL init: %s", SDL_GetError());
        running = false;
    }

    window = SDL_CreateWindow(
            "ARKANOID", 
            SDL_WINDOWPOS_CENTERED, 
            SDL_WINDOWPOS_CENTERED, 
            SCREEN_WIDTH, 
            SCREEN_HEIGHT, 
            SDL_WINDOW_OPENGL);
    if (window == NULL) {
        fprintf(stderr, "Error creating window: %s", SDL_GetError());
        running = false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        fprintf(stderr, "Error creating renderer: %s", SDL_GetError());
        running = false;
    }
    create_paddle(&paddle, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void handle_input(void) {
    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
        running = false;
    }
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_RIGHT: paddle.position.x += PADDLE_STEP; break;
            case SDLK_LEFT: paddle.position.x -= PADDLE_STEP; break;
        }
    }
}

void update(void) {
    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);
    if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME) {
        SDL_Delay(time_to_wait);
    }
    float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;
    last_frame_time = SDL_GetTicks();
    update_paddle(&paddle, SCREEN_WIDTH);
}

void render(void) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);

    render_paddle(renderer, &paddle);

    SDL_RenderPresent(renderer);
}

void loop(void) {
    while (running) {
        handle_input();
        update();
        render();
    }
}

void quit(void) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

