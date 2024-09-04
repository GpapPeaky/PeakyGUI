#include "pgui_draw.hpp"

void PGUI_DrawButton(PGUI_Button button, SDL_Renderer* rnd){
    SDL_RenderCopy(rnd, button.component.background.texture, NULL, &button.component.rect);
    return;
}