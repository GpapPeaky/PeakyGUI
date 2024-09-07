#include "_includes.hpp"

int main(int argc, char* argv[]){

    init_win(); /* Initialise */

    bool quit = false;

    PGUI_CreateItem(PGUI_CreateComponent(1920 - IMG_Load("PeakyGUI/assets/bar.png")->w, 0, PGUI_UNDECIDED_VALUE, PGUI_UNDECIDED_VALUE, IMG_Load("PeakyGUI/assets/bar.png"), rnd), /* background comp */
    {
    PGUI_CreateButton(PGUI_Exit, PGUI_CreateComponent(1920 - IMG_Load("PeakyGUI/assets/cls.png")->w, 0, PGUI_UNDECIDED_VALUE, PGUI_UNDECIDED_VALUE, IMG_Load("PeakyGUI/assets/cls.png"), rnd)),
    PGUI_CreateButton(PGUI_Increment, PGUI_CreateComponent(1920 - 25 -  IMG_Load("PeakyGUI/assets/inc.png")->w, 200, PGUI_UNDECIDED_VALUE, PGUI_UNDECIDED_VALUE, IMG_Load("PeakyGUI/assets/inc.png"), rnd)),
    PGUI_CreateButton(PGUI_DebugPrint, PGUI_CreateComponent(1920 - 25 -  IMG_Load("PeakyGUI/assets/dbg.png")->w, 450, PGUI_UNDECIDED_VALUE, PGUI_UNDECIDED_VALUE, IMG_Load("PeakyGUI/assets/dbg.png"), rnd))
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
