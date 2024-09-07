#include "_includes.hpp"

int main(int argc, char* argv[]){

    init_win(); /* Initialise */

    bool quit = false;

    PGUI_CreateItem(PGUI_CreateComponent(1920 - IMG_Load("PeakyGUI/assets/leftbar.png")->w, 0, PGUI_UNDECIDED_VALUE, PGUI_UNDECIDED_VALUE, IMG_Load("PeakyGUI/assets/leftbar.png"), rnd),
    {
    PGUI_CreateButton(PGUI_DebugPrint, PGUI_CreateComponent(1920 - IMG_Load("PeakyGUI/assets/close.png")->w, 0, PGUI_UNDECIDED_VALUE, PGUI_UNDECIDED_VALUE, IMG_Load("PeakyGUI/assets/close.png"), rnd)),
    PGUI_CreateButton(PGUI_Increment, PGUI_CreateComponent(1920 -  IMG_Load("PeakyGUI/assets/shieldFrame.png")->w, 200, PGUI_UNDECIDED_VALUE, PGUI_UNDECIDED_VALUE, IMG_Load("PeakyGUI/assets/shieldFrame.png"), rnd))
    });

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
