#include "pgui_item.hpp"

std::unordered_map<int, PGUI_Item> PGUI_GlobalItems;
int PGUI_ItemCount = 0;

PGUI_Item PGUI_CreateItem(PGUI_Component component, std::vector<PGUI_Button> buttons){
    PGUI_Item new_item;
    new_item.itemComponent = component;
    new_item.itemButtons = buttons;
    PGUI_GlobalItems[PGUI_ItemCount++] = new_item; /* Pass the item onto the map */

    return new_item;
}

PGUI_Item PGUI_CreateItemComplete(int x, int y, SDL_Surface* itemBackground, SDL_Renderer* rnd, std::vector<PGUI_Button> buttons){
    PGUI_Component cmp = PGUI_CreateComponent(x, y, PGUI_UNDECIDED_VALUE, PGUI_UNDECIDED_VALUE, itemBackground, rnd);

    return PGUI_CreateItem(cmp, buttons);
}

void* PGUI_CreateItemWrapper(std::vector<void*> args){
    int x = *static_cast<int*>(args[0]); 
    int y = *static_cast<int*>(args[1]);
    SDL_Surface* buttonImage = static_cast<SDL_Surface*>(args[2]);
    if(!buttonImage){
        std::cerr << "Error: Invalid SDL_Surface." << std::endl;
        return nullptr;
    }
    SDL_Renderer* rnd = static_cast<SDL_Renderer*>(args[3]);
    if(!rnd){
        std::cerr << "Error: Invalid SDL_Renderer." << std::endl;
        return nullptr;
    }
    std::vector<PGUI_Button>* buttons = static_cast<std::vector<PGUI_Button>*>(args[4]);

    try{
        PGUI_Item* newItem = new PGUI_Item(PGUI_CreateItemComplete(x, y, buttonImage, rnd, { *buttons }));

        // Return the pointer to the newly created item (optional)
        return static_cast<void*>(&PGUI_GlobalItems[PGUI_ItemCount - 1]);
    }catch(const std::bad_alloc& e){
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        return nullptr;
    }catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
        return nullptr;
    }

    return static_cast<void*>(&PGUI_GlobalItems[PGUI_ItemCount - 1]);
}
