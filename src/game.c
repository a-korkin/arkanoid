#include <SDL2/SDL_events.h>
#include <stdio.h>
#include <stdbool.h>
#include "./game.h"
#include "./paddle.h"

#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
bool running = false;
Paddle paddle;

void create_paddle(void) {
    paddle.w = 50;
    paddle.h = 10;
    paddle.position.x = SCREEN_WIDTH / 2;
    paddle.position.y = SCREEN_HEIGHT - 20;
    paddle.color.r = 0x00;
    paddle.color.g = 0xFF;
    paddle.color.b = 0x00;
    paddle.color.a = 0xFF;
}

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
    create_paddle();
}

void handle_input(void) {
    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
        running = false;
    }
}

void update(void) {
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

