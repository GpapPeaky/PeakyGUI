#include "pgui_bar.hpp"

PGUI_IntBar* PGUI_CreateIntegerBar(PGUI_Component background, PGUI_Component foreground,\
int max, int min, int rateOfChange, int* variable, int initial, SDL_Renderer* rnd){
    PGUI_IntBar* newIntegerBar = new PGUI_IntBar;

    newIntegerBar->backgroundComponent = background;  
    newIntegerBar->foregroundComponent = foreground;   
    newIntegerBar->initial = initial;
    newIntegerBar->maxVariableValue = max;
    newIntegerBar->minVariableValue = min;
    newIntegerBar->rateOfChange = rateOfChange;
    newIntegerBar->uniformVariable = variable;

    return newIntegerBar;
}

PGUI_IntBar* PGUI_CreateIntegerBarMargin(int x, int y, int marginSize, SDL_Surface* background,\
SDL_Surface* foreground, int min, int max, int rateOfChange, int* variable, int initial, SDL_Renderer* rnd){
    PGUI_Component backgroundComponent = PGUI_CreateComponent(x, y, PGUI_UNDECIDED_VALUE,\
    PGUI_UNDECIDED_VALUE, background, rnd);
    PGUI_Component foregroundComponent = PGUI_CreateComponent(x + marginSize, y + marginSize, PGUI_UNDECIDED_VALUE,\
    PGUI_UNDECIDED_VALUE, foreground, rnd);

    return PGUI_CreateIntegerBar(backgroundComponent, foregroundComponent, max, min, rateOfChange, variable, initial);
}

void PGUI_GetIntegerBarAttributes(PGUI_IntBar integerBar, int* backX, int* backY, int* foreX, int* foreY, int* min, int* max,\
int* rateOfChange){
    if(backX) *backX = integerBar.backgroundComponent.rect.x;
    if(backY) *backY = integerBar.backgroundComponent.rect.y;
    if(foreX) *foreX = integerBar.foregroundComponent.rect.x;
    if(foreY) *foreY = integerBar.foregroundComponent.rect.y;
    if(min) *min = integerBar.minVariableValue;
    if(max) *max = integerBar.maxVariableValue;
    if(rateOfChange) *rateOfChange = integerBar.rateOfChange;

    return;
}

void PGUI_QueryIntegerBarAttributes(PGUI_IntBar integerBar, int* backX, int* backY, int* foreX, int* foreY, int* min, int* max,\
int* rateOfChange){
    PGUI_GetIntegerBarAttributes(integerBar, backX, backY, foreX, foreY, min, max, rateOfChange);
    
    return;
}
