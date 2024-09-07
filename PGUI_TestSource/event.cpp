#include "event.hpp"

int mouse_x, mouse_y;

void handle_events(bool& quit){
    SDL_Event e;

    while(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_ESCAPE || e.key.keysym.sym == SDLK_e))){
            quit = true;
        }
        if(e.type == SDL_MOUSEBUTTONDOWN){
            if(e.button.button == SDL_BUTTON_LEFT){
                /* Check for button interactions */
                SDL_GetMouseState(&mouse_x, &mouse_y);
                PGUI_EventCycle(mouse_x, mouse_y);
            }
        }
    }

    return;
}
