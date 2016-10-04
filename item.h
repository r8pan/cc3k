#ifndef ITEM_H
#define ITEM_H

#include "gameobject.h"

class GameObject;

enum itemType {potion, treasure};

class Item : public GameObject {
    
   
    itemType it;

  public:
    Item(int x, int y, itemType iType, GOType gType);
    itemType getItemType();
    virtual void tick() = 0;//We write it in subclasses, but it will do nothing.
    
};

#endif
