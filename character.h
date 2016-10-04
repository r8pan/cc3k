#ifndef CHARACTER_H
#define CHARACTER_H

#include "gameobject.h"

//class GameObject;

enum characterType{player,enemy};

class Character : public GameObject {

    int _hp;
    int _atk;
    int _def;
    //bool _me;
    characterType ct;

  public:
    Character(characterType cType, int x, int y, GOType gType);
    void hp(int hp);
    void atk(int atk);
    void def(int def);
    int hp() const;
    int atk() const;
    int def() const;
    //void me(bool b);
    //bool getMe();
    characterType getCharacterType();

    //virtual void tick();   I think we'll implement tick in the sub classes
    virtual void move() = 0;
    virtual void attack() = 0;

};

#endif
