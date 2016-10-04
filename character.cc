#include "character.h"


Character::Character(characterType cType, int x, int y, GOType gType) : GameObject(x, y, gType) {
    ct = cType;
}

void Character::hp(int hp) {
    _hp = hp;
}

void Character::atk(int atk) {
    _atk = atk;
}

void Character::def(int def) {
    _def = def;
}

int Character::hp() const{
    return _hp;
}

int Character::atk() const{
    return _atk;
}

int Character::def() const{
    return _def;
}

