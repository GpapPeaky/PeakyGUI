#include "_includes.hpp"

int main(int argc, char* argv[]){

    init_win(); /* Initialise */

    SDL_Surface* surface = IMG_Load("PeakyGUI/assets/prov_bar.png");
    PGUI_Component comp1 = PGUI_CreateComponent(0, 1080 - surface->h, PGUI_UNDECIDED_VALUE, PGUI_UNDECIDED_VALUE, surface, rnd);
    PGUI_PrintComponent(comp1);
    PGUI_Button butt1 = PGUI_CreateButton(PGUI_DebugPrint, comp1);

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
