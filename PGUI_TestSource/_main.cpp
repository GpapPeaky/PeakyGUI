#include "_includes.hpp"

int main(int argc, char* argv[]){

    init_win(); /* Initialise */

    bool quit = false;

    PGUI_Uniform Uvariable; /* Variable to change with the slider */
    PGUI_IntBar* bar = PGUI_CreateIntegerBarMargin(0, 0, 2, PGUI_Load("inc.png"), PGUI_Load("inc.png"),\
    0, 15, 1, (int*)Uvariable, 5, rnd);
    PGUI_PrintIntegerBar(*bar);

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
