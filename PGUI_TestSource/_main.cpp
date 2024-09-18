#include "_includes.hpp" /* TODO: fix documentation */

int main(int argc, char* argv[]){

    init_win(); /* Initialise */

    bool quit = false;

    /* TODO: Revise and refactor the following instructions to be much simpler, for creating buttons that create items */

    /* Important to do like this */
    int val1 = 45;
    int val2 = 277;

    /* We pass the wrapper function, its' arguments and the number of arguments, if required as PGUI_ActionArguments */
    PGUI_ActionArguments incArgs = {PGUI_IncrementWrapper, {}, 0};
    std::vector<PGUI_Button*> buttons;
    buttons.push_back(PGUI_CreateButtonComplete(incArgs, 1600, 400, PGUI_Load("inc.png"), rnd));
    buttons.push_back(PGUI_CreateButtonComplete(incArgs, 1200, 400, PGUI_Load("inc.png"), rnd));

    int item_x = 1200;
    int item_y = 500;
    
    std::vector<void*> args;
    args.push_back(&item_x);
    args.push_back(&item_y);
    args.push_back(PGUI_Load("bar.png"));
    args.push_back(rnd);
    args.push_back(static_cast<void*>(&buttons)); /* Push a vector of buttons */

    std::vector<void*> arg;
    int itemId = 1;
    arg.push_back(&itemId); /* We need to specify the ID each time, for what to delete */

    PGUI_Item createdItem;

    PGUI_ActionArguments newItemArguments = {PGUI_CreateItemWrapper, args, 0};
    PGUI_Button* newItemButton = PGUI_CreateButtonComplete(newItemArguments, 1700, 0, PGUI_Load("dbg.png"), rnd);
    PGUI_ActionArguments destroyButtonArguments {PGUI_DestroyItemByIDWrapper, arg, 0};
    PGUI_Button* destroyItemButton = PGUI_CreateButtonComplete(destroyButtonArguments, 1200, 0, PGUI_Load("shieldFrame.png"), rnd);

    PGUI_CreateItemComplete(0, 0, PGUI_Load("prov_bar.png"), rnd, { newItemButton, destroyItemButton });

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
