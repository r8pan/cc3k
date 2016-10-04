#ifndef __POTION_H_
#define __POTION_H_

#include "item.h"

enum potionType {RH, BA, BD, PH, WA, WD};

class Potion : public Item {
   
    potionType pt;

  public:
    Potion(int x, int y, potionType pType, itemType iType, GOType gType);
    potionType getPotionType();
    virtual void tick();
};

#endif
