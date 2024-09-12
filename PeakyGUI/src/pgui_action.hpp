#include <vector>
#include "pgui_primitives.hpp"

#ifndef __PGUI_ACTION_H__
#define __PGUI_ACTION_H__

typedef void* (*PGUI_ButtonAction)(std::vector<void*> args); /* To be able to cast both the argmunets and the return value */

typedef struct PGUI_actionArguments{
    PGUI_ButtonAction action;
    std::vector<void*> arguments;
    int numOfArgs;
}PGUI_ActionArguments;

#endif
