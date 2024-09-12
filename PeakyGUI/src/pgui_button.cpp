#include "pgui_button.hpp"

PGUI_Button PGUI_CreateButton(PGUI_ActionArguments actionArgs, PGUI_component component){
    PGUI_Button new_button;
    new_button.actionArgs = actionArgs;
    new_button.component.rect = component.rect;
    new_button.component.background = component.background;
    new_button.component.status = PGUI_IsButton;

    return new_button;
}

PGUI_Button PGUI_CreateButtonComplete(PGUI_ActionArguments actionArgs, int x, int y, SDL_Surface* buttonImage, SDL_Renderer* rnd){
    PGUI_Component cmp = PGUI_CreateComponent(x, y, PGUI_UNDECIDED_VALUE, PGUI_UNDECIDED_VALUE, buttonImage, rnd);

    return PGUI_CreateButton(actionArgs, cmp);
}

PGUI_Bool PGUI_ButtonPressed(PGUI_Button button, int x, int y){
    if((x > button.component.rect.x &&
    y > button.component.rect.y &&
    x < button.component.rect.x + button.component.rect.w &&
    y < button.component.rect.y + button.component.rect.h)){
        return PGUI_True;
    }

    return PGUI_False;
}

void PGUI_ExecuteButtonAction(PGUI_button button){
    if(button.actionArgs.action != NULL){
        button.actionArgs.action(button.actionArgs.arguments);
    }else{
        printf("Execute Call\n");
    }
}
