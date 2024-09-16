#include "pgui_component.hpp"
#include "pgui_button.hpp"
#include <unordered_map>
#include <vector>

#ifndef __PGUI_ITEM_H__ 
#define __PGUI_ITEM_H__

typedef struct PGUI_item{
    PGUI_Component itemComponent; /* Adds the background */
    std::vector<PGUI_Button> itemButtons; /* Can be empty if the item has no buttons */
    int visibility;
    Uint ID;
}PGUI_Item;

extern int PGUI_ItemCount;
extern std::unordered_map<int, PGUI_Item> PGUI_GlobalItems;

/**
 * @brief Creates a new item
 * 
 * @param itemComponent component for background
 * @param buttons item's buttons
 */
PGUI_Item PGUI_CreateItem(PGUI_Component itemComponent, std::vector<PGUI_Button> buttons);

/**
 * @brief Creates a new item, better writing
 * 
 * @param x x axis
 * @param y y axis
 * @param itemBackground background surface
 * @param rnd renderer
 * @param buttons item's buttons
 */
PGUI_Item PGUI_CreateItemComplete(int x, int y, SDL_Surface* itemBackground, SDL_Renderer* rnd, std::vector<PGUI_Button> buttons);

/**
 * @brief Creates a new item, better writing
 * 
 * @param args arguments
 * @note x x axis
 * @note y y axis
 * @note itemBackground background surface
 * @note rnd renderer
 * @note buttons item's buttons
 * 
 * @returns pointer to the created item
 */
void* PGUI_CreateItemWrapper(std::vector<void*> args);

/**
 * @brief Destroys a specified item
 * 
 * @param item item to destroy
 */
void PGUI_DestroyItem(PGUI_Item item);

/**
 * @brief Destroys a specified item by id
 * 
 * @attention We encourage user to use this function (and it's wrapper) instead of the PGUI_DestroyItem one if you wan't to handle many buttons
 * 
 * @param itemID id of the item we want to destroy
 */
void PGUI_DestroyItemByID(Uint itemID);

/**
 * @brief Destroys a specified item
 * 
 * @param args arguments
 * @note item to destroy
 * 
 * @returns NULL
 */
void* PGUI_DestroyItemWrapper(std::vector<void*> args);

/**
 * @brief Destroys a specified item by id
 * 
 * @param args arguments
 * @note item to destroy
 * 
 * @returns NULL
 */
void* PGUI_DestroyItemByIDWrapper(std::vector<void*> args);

#endif
