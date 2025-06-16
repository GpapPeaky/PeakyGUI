#include "SDL.h"
#include "SDL_image.h"
#include "../PeakyGUI/src/PGUI.hpp"

#ifndef __EVENT_H__
#define __EVENT_H__

extern int mouse_x, mouse_y;

/**
 * @brief Handles main loop events
 * 
 * @param quit Checks if we have quit the main loop
 */
void handle_events(bool& quit);

#endif
