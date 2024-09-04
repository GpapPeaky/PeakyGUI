#include "event.hpp"

void handle_events(bool quit){
    SDL_Event e;

    while(SDL_PollEvent(&e)){
        if(e.key.keysym.sym == SDLK_ESCAPE || e.key.keysym.sym == SDLK_e || e.type == SDL_QUIT){
            quit = true;
        }
    }

    return;
}