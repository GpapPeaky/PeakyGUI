#include "SDL.h"            /* These here are the only libraries that require spcific linking, in respect to the local lib directories */
#include "SDL_image.h"
#include "PGUI_debug.hpp"
#include <iostream>

/* TODO: Might add namespaces for more flexible c++ use */

#ifndef __PGUI_PRIMITIVES_H__
#define __PGUI_PRIMITIVES_H__

typedef unsigned int Uint;
typedef bool PGUI_Bool;

/* Redundant definitions */
#define PGUI_SHOWN true
#define PGUI_HIDDEN false

#define PGUI_True true
#define PGUI_False false

#define PGUI_TRUE PGUI_True
#define PGUI_FALSE PGUI_False

typedef SDL_Rect PGUI_Rect;

#define PGUI_UNDECIDED_VALUE 26112004
#define PUV PGUI_UNDECIDED_VALUE

#define PGUI_EXIT_SUCCESS 0
#define PES PGUI_EXIT_SUCCESS
#define PGUI_EXIT_FAIL -1
#define PEF PGUI_EXIT_FAIL

typedef struct PGUI_background{
    SDL_Surface* surface;
    SDL_Texture* texture;
}PGUI_Background;

#endif
