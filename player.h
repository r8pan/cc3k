#ifndef PLAYER_H
#define PLAYER_H

#include "potion.h"
#include "game.h"
#include "gameobject.h"
#include "character.h"
#include "enemy.h"

class GameObject;
class Potion;

enum playerType {knight, wizard, samurai};

class Player : public Character {

    playerType plt;
    bool visible;
    int gold; 

  public:
    Player(playerType plType, bool v, characterType cType, int x, int y, GOType gType);
    void drink(Potion &p);
    void setGold(int g);
    void attacked(int health); //deduct hp
    int getGold();
    void gainHP(); //5 every turn  
    void collectGold(int d);
    void move(std::string dir);
    void attack(std::string dir);
    void addLocation(Cell * _location);
    void resetAD();    //reset atk and def when entering a new level
    //void tick();
};

#endif
