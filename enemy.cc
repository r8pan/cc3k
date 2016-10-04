#include <math.h>
#include "enemy.h"
#include "PRNG.h"

class Character;
class Potion;

Enemy::Enemy(enemyType eType, characterType cType, int x, int y, GOType gType) : Character(cType, x, y, gType) {
    et = eType;
    hostile = true;
    me(false);
    numNeighbors = 8;
    for (int i = 0; i < 8; i++) {
	neighbors[i] = -1;
    }
    if (et == GridBug) {
	hp(50);
	Character::atk(20);
	def(10);
	display('X');
    }
    else if (et == Goblin) {
	hp(75);
	Character::atk(30);
	def(20);
	display('g');
    }
    else if (et == Merchant) {
	hp(100);
	Character::atk(75);
	def(5);
	display('M');
	hostile = false;
    }
    else if (et == Orc) {
	hp(120);
	Character::atk(30);
	def(30);
	display('O');
    }
    else {
	hp(150);
	Character::atk(50);
	def(10);
	display('D');
    }
}

int Enemy::getEnemyNum() {
    return enemyNum;
}

enemyType Enemy::getEnemyType() {
    return et;
}

/*
void Enemy::dropPotion() {
    PRNG prng;
    int row = this->x();
    int col = this->y();
    delete this;
    int k = prng(5);
    switch (k) {
	potionType pT;
	itemType iT = Potion;
	GOType goT = Item;
      case 0:
	  pT = RH;
          board->floor[row][col]._contents = new Potion(row, col, pT, iT, goT);
          break;
      case 1:
	  pT = BA;
          board->floor[row][col]._contents = new Potion(row, col, pT, iT, goT);
	  break;
      case 2:
	  pT = BD;
	  board->floor[row][col]._contents = new Potion(row, col, pT, iT, goT);
	  break;
      case 3:
	  pT = PH;
	  board->floor[row][col]._contents = new Potion(row, col, pT, iT, goT);
	  break;
      case 4:
	  pT = WA;
	  board->floor[row][col]._contents = new Potion(row, col, pT, iT, goT);
	  break;
      case 5:
	  pT = WD;
	  board->floor[row][col]._contents = new Potion(row, col, pT, iT, goT);
	  break;
    }
    board->floor[row][col]._content->addLocation(row, col);
}
*/
/*
void Enemy::dropGold() {
    int row = this->x();
    int col = this->y();
    delete this;
    board->floor[row][col]._contents = new Treasure(goldPile, treasure, row, col, item);
    board->floor[row][col]._contents->addLocation(&board->floor[row][col]);
    
}
*/
    
int Enemy::addNeighbor(int x, int y) {
    if (board->floor[x][y].getType() != tile) {
	return 0;
    }
    else if (!board->floor[x][y].getOccupied()) {
	return 1;
    }
    else if (board->floor[x][y]._contents->getGOType() == character) {
	if (board->floor[x][y]._contents->getMe()) {
	    return 3;
	}
	else {
	    return 0;
	}
    }
    else if (board->floor[x][y]._contents->getGOType() == item) {
	if (dynamic_cast<Item*>(board->floor[x][y]._contents)->getItemType() == potion && getEnemyType() == Goblin) {
	    return 2;
	}
	else {
	    return 0;
	}
    }
}

void Enemy::addNeighbors() {
    neighbors[0] = addNeighbor(x()-1,y()-1);
    neighbors[1] = addNeighbor(x(),y()-1);
    neighbors[2] = addNeighbor(x()+1,y()-1);
    neighbors[3] = addNeighbor(x()-1,y());
    neighbors[4] = addNeighbor(x()+1,y());
    neighbors[5] = addNeighbor(x()-1,y()+1);
    neighbors[6] = addNeighbor(x(),y()+1);
    neighbors[7] = addNeighbor(x()+1,y()+1);
}

void Enemy::resetNeighbors() {
    for (int i = 0; i < 8; i++) {
	neighbors[i] = -1;
    }
}

void Enemy::attack() {
    int damage = ceil(this->Character::atk()*((100-player->def())/100));
    player->attacked(damage);
}

void Enemy::attacked(int atk) {
    int damage = ceil(atk*((100-this->Character::def())/100));
    hp(hp()-damage);
    if (hp() <= 0) {	
	board->floor[x()][y()].display('.');
	board->floor[x()][y()].setOccupied(false);
	board->floor[x()][y()].addGameObject(NULL);
	
	//else if (this->getEnemyType() == GridBug) {
	//    dropPotion();
	//}
    }
}

void Enemy::move() {
    int empty = 0;
    for (int i = 0; i < 7; i++) {
	if (neighbors[i] == 1) {
	    empty++;
	}
    }
    PRNG prng;
    int loc = prng(empty);
    int find= 0;
    for (int i = 0; find != loc; i++) {
	if (neighbors[i] == 1 || neighbors[i] == 2) {
	    find++;
	}
    }
    if (find == 0) {
        addLocation(&board->floor[x()-1][y()-1]);
	board->floor[x()][y()]._contents = NULL;
	board->floor[x()][y()].display('.');
	board->floor[x()][y()].setOccupied(false);
	board->floor[x()-1][y()-1].addGameObject(this);
    }
    else if (find == 1) {
        addLocation(&board->floor[x()][y()-1]);
	board->floor[x()][y()]._contents = NULL;
	board->floor[x()][y()].display('.');
	board->floor[x()][y()].setOccupied(false);
	board->floor[x()][y()-1].addGameObject(this);
    }
    else if (find == 2) {
        addLocation(&board->floor[x()+1][y()-1]);
	board->floor[x()][y()]._contents = NULL;
	board->floor[x()][y()].display('.');
	board->floor[x()][y()].setOccupied(false);
	board->floor[x()+1][y()-1].addGameObject(this);
    }
    else if (find == 3) {
        addLocation(&board->floor[x()-1][y()]);
        board->floor[x()][y()]._contents = NULL;
        board->floor[x()][y()].display ('.');
        board->floor[x()][y()].setOccupied(false);
        board->floor[x()-1][y()].addGameObject(this);
    }
    else if (find == 4) {
        addLocation(&board->floor[x()+1][y()]);
	board->floor[x()][y()]._contents = NULL;
	board->floor[x()][y()].display('.');
	board->floor[x()][y()].setOccupied(false);
	board->floor[x()+1][y()].addGameObject(this);
    }
    else if (find == 5) {
	addLocation(&board->floor[x()-1][y()+1]);
	board->floor[x()][y()]._contents = NULL;
	board->floor[x()][y()].display('.');
	board->floor[x()][y()].setOccupied(false);
	board->floor[x()-1][y()+1].addGameObject(this);
    }
    else if (find == 6) {
        addLocation(&board->floor[x()][y()+1]);
	board->floor[x()][y()]._contents = NULL;
	board->floor[x()][y()].display('.');
	board->floor[x()][y()].setOccupied(false);
	board->floor[x()][y()+1].addGameObject(this);
    }
    else if (find == 7) {
        addLocation(&board->floor[x()+1][y()+1]);
        board->floor[x()][y()]._contents = NULL;
        board->floor[x()][y()].display('.');
        board->floor[x()][y()].setOccupied(false);
        board->floor[x()+1][y()+1].addGameObject(this);
    }
}
/*
void Enemy::drink(Potion &p) {
    if (p.getPotionType() == RH) {
	hp(hp()+30);
    }
    else if (p.getPotionType() == BA) {
	this->atk(atk()+10);
    }
    else if (p.getPotionType() == BD) {
	def(def()+10);
    }
    else if (p.getPotionType() == PH) {
	hp(hp()-15);
	if (hp() <= 0) {
	    board->isWon();
	}
    }
    else if (p.getPotionType() == WA) {
	atk(atk()-5);
    }
    else {
	def(def()-5);
    }
    int row = p.x();
    int col = p.y();
    delete p;
    board->floor[row][col]._contents = NULL;
    board->floor[row][col].display('.');
    board->floor[row][col].setOccupied(false);
}
*/

void Enemy::tick() {
    bool ATK = false;
    bool DRINK = false;
    int index = 0;
    
    for (int i = 0; i < 8; i++) {
	if(neighbors[i] == 3) {
	    ATK = true;
	    break;
        }
    }
    for (int i = 0; i < 8; i++) {
	if(neighbors[i] == 2 && et == Goblin) {
	    DRINK = true;
	    index = i;
	    break;
        }
    }

    if (ATK) {
	attack();
    }
    /*
    else if (DRINK) {
	if (index == 0) {
	    drink(dynamic_cast<Potion*>(&board->floor[x()-1][y()-1]._contents));
	}
	else if (index == 1) {
	    drink(dynamic_cast<Potion*>(&board->floor[x()][y()-1]._contents));
	}
	else if (index == 2) {
	    drink(dynamic_cast<Potion*>(&board->floor[x()+1][y()-1]._contents));
	}
	else if (index == 3) {
	    drink(dynamic_cast<Potion*>(&board->floor[x()-1][y()]._contents));
	}
	else if (index == 4) {
	    drink(dynamic_cast<Potion*>(&board->floor[x()+1][y()]._contents));
	}
	else if (index == 5) {
	    drink(dynamic_cast<Potion*>(&board->floor[x()-1][y()+1]._contents));
	}
	else if (index == 6) {
	    drink(dynamic_cast<Potion*>(&board->floor[x()][y()+1]._contents));
	}
	else if (index == 7) {
	    drink(dynamic_cast<Potion*>(&board->floor[x()+1][y()+1]._contents));
        }
    }
    */
    else {
	move();
    }	
}
