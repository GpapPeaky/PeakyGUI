#include "event.hpp"

void handle_events(bool& quit){
    SDL_Event e;

    while(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_ESCAPE || e.key.keysym.sym == SDLK_e))){
            quit = true;
        }
    }

    return;
}