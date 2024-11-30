#include "_includes.hpp"

int main(int argc, char* argv[]){

    init_win(); /* Initialise */

    bool quit = false;

    PGUI_Uniform Uvariable; /* Variable to change with the slider */
    PGUI_IntBar* bar = PGUI_CreateIntegerBarMargin(0, 0, 50, PGUI_Load("bgbar.png"), PGUI_Load("frbar.png"),\
    0, 15, 1, (int*)Uvariable, 5, rnd);
    PGUI_PrintIntegerBar(*bar);

    PGUI_Widget* widget = PGUI_CreateWidgetComplete(0, 0, PGUI_Load("butt.png"), rnd, {}, PGUI_True);
    PGUI_AddIntegerBarToWidget(widget, bar);

    /* Visibility status check */
    PGUI_ActionArguments visArg = { PGUI_ItemVisibilitySwitchWrapper, {widget}, 1} ;
    PGUI_Widget* visButtonWidget = PGUI_CreateButtonAsWidget(visArg, 250, 0, PGUI_Load("inc.png"), rnd, PGUI_True);

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
