#include "item.h"


Item::Item(int x, int y, itemType type, GOType gType) : GameObject(x,y,gType) {
    it = type;
}

itemType Item::getItemType(){
    return it;
}
