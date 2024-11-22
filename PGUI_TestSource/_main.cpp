#include "_includes.hpp"

int main(int argc, char* argv[]){

    init_win(); /* Initialise */

    bool quit = false;

    PGUI_Uniform Uvariable;
    PGUI_IntBar* bar = PGUI_CreateIntegerBarMargin(0, 0, 2, PGUI_Load("inc.png"), PGUI_Load("inc.png"), 0, 15, 1, (int*)Uvariable, 5);
    PGUI_PrintIntegerBar(*bar);

    /* Widget to change visibility of */
    PGUI_ActionArguments incButtonArgs = { PGUI_IncrementWrapper, {} , 0 };
    PGUI_Button* incButton1 =  PGUI_CreateButtonComplete(incButtonArgs, 0, 0, PGUI_Load("inc.png"), rnd);
    PGUI_Button* incButton2 =  PGUI_CreateButtonComplete(incButtonArgs, 0, 200, PGUI_Load("inc.png"), rnd);
    PGUI_Widget* switchWidget = PGUI_CreateWidgetComplete(0, 700, PGUI_Load("shieldFrame.png"), rnd, { incButton1, incButton2 }, PGUI_False);

    PGUI_CreateButtonAsWidget(incButtonArgs, 500, 500, PGUI_Load("inc.png"), rnd, PGUI_True); /* Faster approach to show just buttons as whole Widgets */

    /* Button that changes the visibility*/
    PGUI_ActionArguments switchButtonArgs = { PGUI_WidgetVisibilitySwitchWrapper, { switchWidget }, 1};
    PGUI_Button* visibilityButton = PGUI_CreateButtonComplete(switchButtonArgs, 1000, 0, PGUI_Load("butt.png"), rnd);
    PGUI_CreateWidgetComplete(0, 0, PGUI_Load("leftbar.png"), rnd, { visibilityButton }, PGUI_True);

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

        PGUI_DrawWidgets(rnd);

        SDL_RenderPresent(rnd);
    }

    PGUI_Cleanup();
    SDL_DestroyRenderer(rnd);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return PGUI_EXIT_SUCCESS;
}
