#include "pgui_component.hpp"
#include "pgui_button.hpp"
#include <unordered_map>
#include <vector>

#ifndef __PGUI_ITEM_H__ 
#define __PGUI_ITEM_H__

typedef struct PGUI_item{
    PGUI_Component itemComponent; /* Adds the background */
    std::vector<PGUI_Button> itemButtons; /* Can be empty if the item has no buttons */
}PGUI_Item;

extern int PGUI_ItemCount;
extern std::unordered_map<int, PGUI_Item> PGUI_GlobalItems;

/**
 * @brief Creates a new item
 * 
 * @param itemComponent component for background
 * @param buttons item's buttons
 */
PGUI_Item PGUI_CreateItem(PGUI_Component itemComponent, std::initializer_list<PGUI_Button> buttons);

/**
 * @brief Creates a new item, better writing
 * 
 * @param x x axis
 * @param y y axis
 * @param itemBackground background surface
 * @param rnd renderer
 * @param buttons item's buttons
 */
PGUI_Item PGUI_CreateItemComplete(int x, int y, SDL_Surface* itemBackground, SDL_Renderer* rnd, std::initializer_list<PGUI_Button> buttons);

#endif
