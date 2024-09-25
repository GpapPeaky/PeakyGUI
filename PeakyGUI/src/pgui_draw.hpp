#include "SDL.h"
#include "SDL_image.h"
#include "pgui_button.hpp"
#include "pgui_item.hpp"
#include <cstring>
#include <iostream>

#ifndef __PGUI_DRAW_H__
#define __PGUI_DRAW_H__

extern const char* PGUI_AssetPath;

/**
 * @brief Loads a .png form them PGUI assets
 * 
 * @param fname asset to load
 * @param flags flags for the component
 * 
 * @attention flag: PGUI_LOAD_COMPONENT, loads the component normally
 * @attention flag: PGUI_EMPTY_COMPONENT, loads an empty component
 * 
 * @returns the loaded surface (or NULL if empty)
 */
SDL_Surface* PGUI_Load(const char* fname, int flags = PGUI_LOAD_COMPONENT);

/**
 * @brief Draws a specific button to the screen
 * 
 * @param button button to draw
 * @param rnd renderer to use
 */
void PGUI_DrawButton(PGUI_Button button, SDL_Renderer* rnd);

/**
 * @brief Higlights the clicked button
 * 
 * @param button button to higlight
 * @param rnd renderer to use
 */
void PGUI_HighlightButtonOnClick(PGUI_Button button, SDL_Renderer* rnd);

/**
 * @brief Draws a specific button to the screen
 * 
 * @param item item to draw
 * @param rnd renderer to use
 */
void PGUI_DrawItem(PGUI_Item item, SDL_Renderer* rnd);

/**
 * @brief Draws all items, saved in the PGUI_GlobalItems unordered map
 * 
 * @param rnd renderer to use
 */
void PGUI_DrawItems(SDL_Renderer* rnd);

#endif
