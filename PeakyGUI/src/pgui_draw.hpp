#include "pgui_button.hpp"
#include "pgui_item.hpp"
#include <algorithm> /* For std::sort */

#ifndef __PGUI_DRAW_H__
#define __PGUI_DRAW_H__

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
 * @brief Draws all items, saved in the PGUI_GlobalItems unordered map but sorted
 * so that the first widget created is rendered first (FIFO rendition)
 * 
 * @param rnd renderer to use
 */
void PGUI_DrawItems(SDL_Renderer* rnd);

/* Function Overloads */

#define PGUI_DrawWidget PGUI_DrawItem
#define PGUI_DrawWidgets PGUI_DrawItems

#endif
