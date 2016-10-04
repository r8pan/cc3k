#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <vector>

using namespace std;

// forward declaration because mutual reference
class GameObject;

enum Type {wall, empty, passage, doorway, staircase, tile};

class Cell {
    //static TextDisplay *floor;
    int _x, _y;
    int _chamber;
    char _display;
    Type t;
      
   
   

  public:
    GameObject *_contents;
    bool occupied;
    vector< vector< vector<int> > > Chambers; //contains list Coord pairs for each cell inside a chamber
    Cell();
    Cell(int x, int y, int chamber, char display); 
    int x() const;
    int y() const;
    char display() const;
    Type getType() const;
    bool getOccupied() const;
    void setOccupied(bool);
    void display(char d);
    void setCoords(int r, int c);
    void addGameObject(GameObject *gameObj);
    void setChamber(int r, int c);
    //void addDisplay();
    //void levelUp();
    Cell& operator=(const Cell&);
};
    
#endif
