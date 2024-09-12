#include "_includes.hpp"

int main(int argc, char* argv[]){

    init_win(); /* Initialise */

    bool quit = false;

    PGUI_Button inc = PGUI_CreateButtonComplete(PGUI_Increment, 0, 0, IMG_Load("PeakyGUI/assets/inc.png"), rnd);
    PGUI_Button cls = PGUI_CreateButtonComplete(PGUI_Exit, 0, 75, IMG_Load("PeakyGUI/assets/cls.png"), rnd);
    PGUI_Button dbg = PGUI_CreateButtonComplete(PGUI_DebugPrint, 0, 150, IMG_Load("PeakyGUI/assets/dbg.png"), rnd);
    PGUI_CreateItemComplete(0, 0, IMG_Load("PeakyGUI/assets/leftbar.png"), rnd, {inc, cls, dbg});

    while(!quit){
        /* Updates to assets / sprites */
        handle_events(quit); /* Creates a new event to poll per call (Might need to be optimised) */

        /* Render functions */
        SDL_RenderClear(rnd);

        PGUI_DrawItems(rnd);

        SDL_RenderPresent(rnd);
    }

    SDL_DestroyRenderer(rnd);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
