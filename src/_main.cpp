#include "_includes.hpp"

int main(int argc, char* argv[]){

    init_win(); /* Initialise */

    SDL_Surface* surface = IMG_Load("PeakyGUI/assets/box1.png");
    PGUI_Component comp1 = PGUI_CreateComponent(0, 0, 150, 150, surface, rnd);
    PGUI_Button butt1 = PGUI_CreateButton(PGUI_Increment, comp1);

    bool quit = false;

    while(!quit){
        /* Updates to assets / sprites */
        handle_events(quit); /* Creates a new event to poll per call (Might need to be optimised) */

        /* Render functions */
        SDL_RenderClear(rnd);

        PGUI_DrawButton(butt1, rnd);
        
        SDL_RenderPresent(rnd);
    }

    SDL_DestroyRenderer(rnd);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
