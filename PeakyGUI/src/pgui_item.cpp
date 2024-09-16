#include "pgui_item.hpp"

std::unordered_map<int, PGUI_Item> PGUI_GlobalItems;
int PGUI_ItemCount = 0;

/* TODO: Make it so that when a new item is created via a button press, it is only created and destroyed once */

PGUI_Item PGUI_CreateItem(PGUI_Component component, std::vector<PGUI_Button> buttons){
    PGUI_Item new_item;
    new_item.itemComponent = component;
    new_item.itemButtons = buttons;
    new_item.visibility = PGUI_True;
    new_item.ID = PGUI_ItemCount; /* Save in order to delete later */
    PGUI_GlobalItems[PGUI_ItemCount++] = new_item; /* Pass the item onto the map */

    #ifdef PGUI_DEBUG
        std::printf("Button with ID %d created and passed\n", new_item.ID);
    #endif /* PGUI_DEBUG */

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
        std::printf("PGUI ERROR: BUTTON SURFACE\n");
        return nullptr;
    }
    SDL_Renderer* rnd = static_cast<SDL_Renderer*>(args[3]);
    if(!rnd){
        std::printf("PGUI ERROR: RENDERER");
        return nullptr;
    }
    std::vector<PGUI_Button>* buttons = static_cast<std::vector<PGUI_Button>*>(args[4]);

    PGUI_Item* newItem = new PGUI_Item(PGUI_CreateItemComplete(x, y, buttonImage, rnd, { *buttons }));
    newItem->visibility = PGUI_False; /* Not visible at first */

    return static_cast<void*>(&PGUI_GlobalItems[PGUI_ItemCount - 1]);
}

void PGUI_DestroyItem(PGUI_Item item){
    auto it = PGUI_GlobalItems.find(item.ID);
    if(it != PGUI_GlobalItems.end()){
        item.itemButtons.clear(); /* delete all buttons */
        /* Remove the item from the map */
        PGUI_GlobalItems.erase(it);
        PGUI_ItemCount--; /* Decrement the count */
    }else{
        std::printf("Button destruction failed\n");
    }

    return;
}

void PGUI_DestroyItemByID(Uint itemID){
    auto it = PGUI_GlobalItems.find(itemID);
    if(it != PGUI_GlobalItems.end()){
        PGUI_Item& foundItem = it->second;
        foundItem.itemButtons.clear(); /* delete all buttons */
        /* Remove the item from the map */
        PGUI_GlobalItems.erase(it);
        PGUI_ItemCount--; /* Decrement the count */
    }else{
        std::printf("Item destruction failed\n");
    }

    return;
}

void* PGUI_DestroyItemWrapper(std::vector<void*> args){
    PGUI_DestroyItem(*static_cast<PGUI_Item*>(args[0]));

    return NULL;
}

void* PGUI_DestroyItemByIDWrapper(std::vector<void*> args){
    PGUI_DestroyItemByID(*static_cast<Uint*>(args[0]));

    return NULL;
}
