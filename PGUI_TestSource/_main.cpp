#include "_includes.hpp" /* TODO: fix documentation */

int main(int argc, char* argv[]){

    init_win(); /* Initialise */

    bool quit = false;

    /* Important to do like this */
    int val1 = 1;
    int val2 = 5;

    /* We pass the wrapper function, it's arguments and the number of arguments, if required as PGUI_ActionArguments */
    PGUI_ActionArguments closeArgs = {PGUI_Sum, {&val1, &val2}, 2};
    PGUI_Button close = PGUI_CreateButtonComplete(closeArgs, 0, 0, PGUI_Load("cls.png") ,rnd);
    PGUI_ActionArguments incArgs = {PGUI_IncrementWrapper, {}, 0};
    PGUI_Button inc = PGUI_CreateButtonComplete(incArgs, 1600, 400, PGUI_Load("inc.png"), rnd);
    PGUI_ActionArguments debugArgs = {PGUI_DebugWrapper, {}, 0};
    PGUI_Button debug = PGUI_CreateButtonComplete(debugArgs, 1500, 0, PGUI_Load("dbg.png"), rnd);

    PGUI_CreateItemComplete(0, 0, PGUI_Load("prov_bar.png"), rnd, { close, inc, debug});

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
