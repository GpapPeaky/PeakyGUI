#include "pgui_bar.hpp"

PGUI_IntBar* PGUI_CreateIntegerBar(PGUI_Component background, PGUI_Component foreground,\
int max, int min, int rateOfChange, int* variable, int default){
    PGUI_IntBar* newIntegerBar = new PGUI_IntBar;

    newIntegerBar->backgroundComponent = background;  
    newIntegerBar->foregroundComponent = foreground;   
    newIntegerBar->default = default;
    newIntegerBar->maxVariableValue = max;
    newIntegerBar->minVariableValue = min;
    newIntegerBar->rateOfChange = rateOfChange;
    newIntegerBar->uniformVariable = variable;

    return newIntegerBar;
}
