#include "pgui_draw.hpp"

const char* PGUI_AssetPath = "PeakyGUI/assets/";

SDL_Surface* PGUI_Load(const char* fname){
    size_t pathLength = strlen(PGUI_AssetPath) + strlen(fname) + 1;
    char* fullPath = new char[pathLength];

    /* Construct the path */
    snprintf(fullPath, pathLength, "%s%s", PGUI_AssetPath, fname);

    SDL_Surface* surface = IMG_Load(fullPath);
    
    /* Check for errors */
    if(surface == nullptr){
        std::cerr << "Error loading image: " << IMG_GetError() << std::endl;
    }

    delete[] fullPath;
    return surface;
 }

void PGUI_DrawComponent(PGUI_Component comp, SDL_Renderer* rnd){
    SDL_RenderCopy(rnd, comp.background.texture, NULL, &comp.rect);
    return;
}

void PGUI_HighlightButtonOnClick(PGUI_Button button, SDL_Renderer* rnd){
    SDL_SetRenderDrawColor(rnd, 255 ,255, 255, 150);
    SDL_RenderDrawRect(rnd, &button.component.rect);

    return;
}

void PGUI_DrawItem(PGUI_Item item, SDL_Renderer* rnd){
    PGUI_DrawComponent(item.itemComponent, rnd);
    for(auto button : item.itemButtons){
        PGUI_DrawComponent((*button).component, rnd);
    }

    return;
}

void PGUI_DrawItems(SDL_Renderer* rnd){
    for(auto it = PGUI_GlobalItems.begin() ; it != PGUI_GlobalItems.end() ; ++it){
        PGUI_Item* item = it->second;
        
        PGUI_DrawItem(*item, rnd);
    }

    return;
}

