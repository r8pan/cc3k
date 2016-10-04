#include "treasure.h"


Treasure::Treasure(treasureType tType, itemType iType, int x, int y, GOType gType):  Item(x, y, iType, gType) {
    tr = tType;
    display('$');
    if (tr == GoldPile){
	value = 10;
    }
    else if (tr == DragonHoard){
	value = 50;
    }	
}

int Treasure::getTreasureType() {
	return tr;
}

void Treasure::tick() {}

Treasure::~Treasure(){
    delete this;
}


