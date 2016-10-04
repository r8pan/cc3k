#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"

enum treasureType {GoldPile, DragonHoard};

class Treasure : public Item  {
   
    int value;	//initialize accumulated treasure
    treasureType tr;

  public:
    Treasure(treasureType tType, itemType iType, int x, int y, GOType gType);
    int getTreasureType();
    void tick();

    ~Treasure();
};

#endif

