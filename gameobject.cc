#include "gameobject.h"

class Cell;


GameObject::GameObject(int x, int y, GOType gType) {
    _x = x;
    _y = y;
    gt = gType;
    //_location = NULL;
}

GOType GameObject::getGOType() {
    return gt;
}

int GameObject::x() const {
    return _x;
}

int GameObject::y() const{
    return _y;
}

char GameObject::display() {
    return _display;
}

void GameObject::x(int x) {
    _x = x;
}

void GameObject::y(int y) {
    _y = y;
}

void GameObject::display(char d) {
    _display = d;
}

void GameObject::addLocation(Cell *location) {
    _location =location;
}

bool GameObject::getMe() {
    return me;
}

void GameObject::me(bool b) {
    _me = b;
}

















