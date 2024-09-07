#include "init_window.hpp"

SDL_Window* win;
SDL_Renderer* rnd;

void init_win(){

    SDL_Init(SDL_INIT_EVERYTHING);
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
        std::printf("SDL Could Not Initialise, Error: %s\n",SDL_GetError());
        return;
    }

    IMG_Init(IMG_INIT_PNG);
    if(IMG_Init(IMG_INIT_PNG) == 0){
        std::printf("Failed To Initialise PNGs, Error: %s\n",SDL_GetError());
        return;
    }

    /* Initialising window and renderer */

    win = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SDL_WINDOW_FULLSCREEN_DESKTOP, SDL_WINDOW_FULLSCREEN_DESKTOP, SDL_WINDOW_SHOWN);
    if(win == NULL){
        std::printf("Failed To Create Window: %s\n", SDL_GetError());
        return;
    }

    SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN_DESKTOP);

    rnd = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(rnd == NULL){
        std::printf("Failed To Create Renderer: %s\n", SDL_GetError());
        return;
    }

    return;
}
