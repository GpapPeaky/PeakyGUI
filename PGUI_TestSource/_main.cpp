#include "_includes.hpp"

int main(int argc, char* argv[]){

    init_win(); /* Initialise */

    bool quit = false;

    int a = 1;
    int b = 23;

    void* ptrA = &a;
    void* ptrB = &b;

    std::vector<void*> args = {ptrA, ptrB};
    PGUI_ActionArguments actionArgs = { PGUI_Sum, args, 2 };

    PGUI_Button butt = PGUI_CreateButton(actionArgs, 
    PGUI_CreateComponent(0, 0, 0, 0, IMG_Load("PeakyGUI/assets/cls.png"), rnd));

    PGUI_ExecuteButtonAction(butt);

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
