#include "_includes.hpp"

int main(int argc, char* argv[]){

    init_win(); /* Initialise */

    bool quit = false;

    /* Item to change visibility of */
    PGUI_ActionArguments incButtonArgs = { PGUI_IncrementWrapper, {} , 0 };
    PGUI_Button* incButton1 =  PGUI_CreateButtonComplete(incButtonArgs, 0, 0, PGUI_Load("inc.png"), rnd);
    PGUI_Button* incButton2 =  PGUI_CreateButtonComplete(incButtonArgs, 0, 200, PGUI_Load("inc.png"), rnd);
    PGUI_Item* switchItem = PGUI_CreateItemComplete(0, 700, PGUI_Load("shieldFrame.png"), rnd, { incButton1, incButton2 }, PGUI_False);

    PGUI_CreateButtonAsItem(incButtonArgs, 500, 500, PGUI_Load("inc.png"), rnd, PGUI_True); /* Faster approach to show just buttons as whole items */

    /* Button that changes the visibility*/
    PGUI_ActionArguments switchButtonArgs = { PGUI_ItemVisibilitySwitchWrapper, { switchItem }, 1};
    PGUI_Button* visibilityButton = PGUI_CreateButtonComplete(switchButtonArgs, 1000, 0, PGUI_Load("butt.png"), rnd);
    PGUI_CreateItemComplete(0, 0, PGUI_Load("leftbar.png"), rnd, { visibilityButton }, PGUI_True);

    #ifdef PGUI_MEMDEALLOC
        PGUI_Cleanup();
        PGUI_MemoryCheck();
        return PGUI_EXIT_SUCCESS;
    #endif

    while(!quit){
        /* Updates to assets / sprites */
        handle_events(quit); /* Creates a new event to poll per call (Might need to be optTimised) */

        /* Render functions */
        SDL_RenderClear(rnd);

        PGUI_DrawItems(rnd);

        SDL_RenderPresent(rnd);
    }

    PGUI_Cleanup();
    SDL_DestroyRenderer(rnd);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return PGUI_EXIT_SUCCESS;
}
