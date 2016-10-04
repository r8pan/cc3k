#include "potion.h"


Potion::Potion(int x, int y,potionType pType, itemType iType, GOType gType) : Item(x, y, iType,gType) {
    pt = pType;
    display('!');
}

potionType Potion::getPotionType() {
    return pt;
}

void Potion::tick() {}
