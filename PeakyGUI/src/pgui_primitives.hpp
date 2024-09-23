#include "SDL.h"
#include "PGUI_module.hpp"
#include <iostream>
#include <exception>

#ifndef __PGUI_PRIMITIVES_H__
#define __PGUI_PRIMITIVES_H__

typedef unsigned int Uint;
typedef bool PGUI_Bool;

/* Redundant definitions */
#define PGUI_IsButton true
#define PGUI_IsNotButton false

#define PGUI_True true
#define PGUI_False false

typedef SDL_Rect PGUI_Rect;

#define PGUI_UNDECIDED_VALUE 26112004

#define PGUI_EXIT_SUCCESS 0
#define PGUI_EXIT_FAIL -1

typedef struct PGUI_background{
    SDL_Surface* surface;
    SDL_Texture* texture;
}PGUI_Background;

#endif
