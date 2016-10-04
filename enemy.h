#ifndef ENEMY_H_
#define ENEMY_H_

#include "game.h"
#include "gameobject.h"
#include "character.h"
#include "player.h"
#include "potion.h"
#include "treasure.h"

class GameObject;
class Character;
class Player;

enum enemyType{GridBug, Goblin, Merchant, Orc, Dragon};


class Enemy : public Character {

    int numNeighbors;
    int neighbors[];
   
    enemyType et;
    bool hostile;
    static int atk;
    static Player* player;
    int enemyNum;

  public:
    Enemy(enemyType eType, characterType cType, int x, int y, GOType gType);
    enemyType getEnemyType();
    int getEnemyNum();
    int addNeighbor(int x, int y);
    void addNeighbors();
    void move();
    void attack();
    void attacked(int atk);
    void dropGold();
    //void dropPotion();
    void resetNeighbors();
    void drink(Potion &p);
    void tick();
};

#endif
