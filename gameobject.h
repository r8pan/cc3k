#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <iostream>
#include "cell.h"

// forward declaration because mutual reference
class Cell;
class Game;

enum GOType{character, item};

// add public/private/protected members as necessary
class GameObject {
    int _x;
    int _y;
    char _display;
    bool _me;
    GOType gt;
    

  public:
    static Game * board;
    Cell * _location;
    GameObject(int x,int y, GOType gType);
    GOType getGOType();
    int x() const;  // getters
    int y() const;
    char display();
    void x(int);  // setters
    void y(int);
    void display(char d);
    Game* getBoard();
    // Called after every turn
    virtual void tick() = 0;
    void addLocation(Cell *location);
    void me(bool b);
    bool getMe();
};

#endif
