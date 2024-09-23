#include <vector>
#include "pgui_primitives.hpp"

#ifndef __PGUI_ACTION_H__
#define __PGUI_ACTION_H__

typedef std::vector<void*> PGUI_ArgumentVector;
typedef void* (*PGUI_ButtonAction)(PGUI_ArgumentVector args); /* To be able to cast both the argmunets and the return value */

typedef struct PGUI_actionArguments{
    PGUI_ButtonAction action;
    PGUI_ArgumentVector arguments;
    int numOfArgs;
}PGUI_ActionArguments;

#endif
