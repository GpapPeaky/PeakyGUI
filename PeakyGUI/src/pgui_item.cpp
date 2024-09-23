#include "pgui_item.hpp"

std::unordered_map<int, PGUI_Item*> PGUI_GlobalItems;
int PGUI_ItemCount = 0;

/* TODO: Make it so that when a new item is created via a button press, it is only created and destroyed once */
/* TODO: Fix a crashing problem when pressing the creation button after deleting another, as well as the item background not being loaded, after being deleted */

PGUI_Item* PGUI_CreateItem(PGUI_Component component, std::vector<PGUI_Button*> buttons){
    PGUI_Item* new_item = new PGUI_Item; /* Dynamic memory allocation */
    new_item->itemComponent = component;
    new_item->itemButtons = buttons;
    new_item->visibility = PGUI_True;
    new_item->ID = PGUI_ItemCount; /* Save in order to delete later */
    PGUI_GlobalItems[PGUI_ItemCount++] = new_item; /* Pass the item onto the map */

    #ifdef PGUI_DEBUG
        std::printf("Item with ID %d created and passed\n", new_item->ID);
    #endif /* PGUI_DEBUG */

    return new_item;
}

PGUI_Item* PGUI_CreateItemComplete(int x, int y, SDL_Surface* itemBackground, SDL_Renderer* rnd, std::vector<PGUI_Button*> buttons, PGUI_Bool visibility){
    PGUI_Component cmp = PGUI_CreateComponent(x, y, PGUI_UNDECIDED_VALUE, PGUI_UNDECIDED_VALUE, itemBackground, rnd);

    PGUI_Item* item = PGUI_CreateItem(cmp, buttons);
    item->visibility = visibility;

    return item;
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
    std::vector<PGUI_Button*>* buttons = static_cast<std::vector<PGUI_Button*>*>(args[4]);
    int visibility = *static_cast<int*>(args[5]);

    PGUI_Item* newItem = PGUI_CreateItemComplete(x, y, buttonImage, rnd, { *buttons }, visibility);
    newItem->visibility = PGUI_False; /* Not visible at first */

    return static_cast<void*>(&PGUI_GlobalItems[PGUI_ItemCount - 1]);
}

void PGUI_DestroyItem(PGUI_Item item){
    PGUI_DestroyItemByID(item.ID);

    return;
}

void PGUI_DestroyItemByID(Uint itemID){
    auto it = PGUI_GlobalItems.find(itemID);
    if(it != PGUI_GlobalItems.end()){
        PGUI_Item* foundItem = it->second;
        
        /* Erase from the map */
        PGUI_GlobalItems.erase(it);
        /* Clear the vector */
        foundItem->itemButtons.clear();

        if(foundItem->itemComponent.background.surface != NULL){
            SDL_FreeSurface(foundItem->itemComponent.background.surface);
        }
        if(foundItem->itemComponent.background.texture){
            SDL_DestroyTexture(foundItem->itemComponent.background.texture);
        }

        /* Dealloc memory for the button graphics */
        for(PGUI_Button* itemButton : foundItem->itemButtons){
            PGUI_DeleteButton(itemButton);
        }
        /* Dealloc memory */
        if(foundItem != NULL){ delete foundItem; }
        /* Decrement the item count */
        #ifdef PGUI_DEBUG
            std::printf("Item with ID %d destroyed\n", foundItem->ID);
        #endif /* PGUI_DEBUG */
    }else{
        #ifdef PGUI_DEBUG
            std::printf("Item with ID %d couldn't be destroyed\n", itemID);
        #endif /* PGUI_DEBUG */
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

/* Instead of allocating a deallocating memory we will simply change it's visibility */

void PGUI_MakeItemVisible(PGUI_Item* item){
    item->visibility = PGUI_True; /* Change of visibility */
    
    return;
}

void* PGUI_MakeItemVisibleWrapper(std::vector<void*> args){
    PGUI_Item* item= static_cast<PGUI_Item*>(args[0]);

    PGUI_MakeItemVisible(item);

    return NULL;
}

void PGUI_MakeItemInvisible(PGUI_Item* item){
    item->visibility = PGUI_False;

    return;
}

void* PGUI_MakeItemInvisibleWrapper(std::vector<void*> args){
    PGUI_Item* item = static_cast<PGUI_Item*>(args[0]);

    PGUI_MakeItemInvisible(item);

    return NULL;
}

void PGUI_ItemVisibilitySwitch(PGUI_Item* item){
    switch(item->visibility){
        case PGUI_True: /* Visible */
            PGUI_MakeItemInvisible(item);
            break;
        
        case PGUI_False:
            PGUI_MakeItemVisible(item);
            break;
        }

    return;
}

void* PGUI_ItemVisibilitySwitchWrapper(std::vector<void*> args){
    PGUI_Item* item = static_cast<PGUI_Item*>(args[0]);

    PGUI_ItemVisibilitySwitch(item);

    return NULL;
}
