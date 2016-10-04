#include "cell.h"

class Game;
class GameObject;
 
Cell::Cell() {}

Cell::Cell(int x = 0, int y = 0, int cn = 0, char d = '.') {
    _x = x;
    _y = y;
    _chamber = cn;
    _display = d;
    if (d == '-' || d == '|') {
	t = wall;
	occupied = true;
    }
    else if (d == ' ') {
	t = empty;
	occupied = true;
    }
    else if (d == '#') {
	t = passage;
	occupied = true;
    }
    else if (d == '+') {
	t = doorway;
	occupied = true;
    }
    else if (d == '>') {
	t = staircase;
	occupied = true;
    }
    else if (d == '.') {
	t = tile;
	occupied = true;
    }
    //else if (d == '!') {
    //t = Enemy;
//	occupied = true;
    //  }
    //else if (d == '@') {
//	t = Player;
//	occupied = true;
    //  }
    occupied = false;
}

char Cell::display() const{
	return _display;
}

int Cell::x() const {
    return _x;
}

int Cell::y() const {
    return _y;
}

//void Cell::setState(char change)
//	prevState = state;
//	state = change;
//	notifyDisplay();
//}

Type Cell::getType() const {
    return t;
}

//void Cell::setOccupied(bool b) {
//    occupied = b;
//}

void Cell::setOccupied(bool b) {}
void Cell::setCoords(int r,int c){
	_x = r;
	_y = c;
	//notifyDisplay();
}//setCoords

void Cell::setChamber(int r, int c){
	if ((r > 1) && (r < 8) && (c > 1) && (c < 30)){
		_chamber = 0;

	}
	else if ((r>1)&&(r<8)&&(c >37)&&(c<77)&&(t != ' ') || (r>7)&&(r<14)&&(c>59)&&(c<77)){
		_chamber = 1;
	}
	else if ((r>8)&&(r<14)&&(c>36)&&(c<51)){
		_chamber = 2;
	}
	else if ((r>13)&&(r<23)&&(c>2)&&(c<26)){
		_chamber = 3;
	}
	else if ((r>17)&&(r<23)&&(c>35)&&(c<77) || (r>14)&&(r<19)&&(c>63)&&(c<77)){
		_chamber = 4;
	}
	else {
		_chamber = 7; //not in any of the 5 chambers (pathway or empty space)
	}
	//accumulate inner chamber cells, to be used for random generation
	if ((t != wall)||(t != passage)||(t != empty)||(t != doorway)){
	    Chambers[_chamber].push_back(vector<int>());
		for (int j=0; j< Chambers[_chamber].size();j++){
		    Chambers[_chamber][j].push_back(r); //add row value
		    Chambers[_chamber][j].push_back(c); //add row value

		}
	}
		 
}

//void Cell::addNeighbour(Cell * neighbour){
//	if ( numNeighbours != 8 ){
//		numNeighbours++;
//		neighbours[numNeighbours] = neighbour;
//	}
//}

//void Cell::notify(char current, char prevState){
//	if (current != prevState){
//		setState(current);
//	}
//}

//void Cell::addDisplay(TextDisplay * t){
//	display = t;
//}

//void Cell::notifyDisplay(){
//	display->notify(row,col,cellChar);
//}


void Cell::addGameObject(GameObject *gameObj) {
    _contents = gameObj;
}

bool Cell::getOccupied() const {// true if item can 
	return occupied;
}

//bool Cell::levelUp() {
//	if ((prevState == Staircase) && (state == PlayerAny)){
//		return true;		
//      }
//	else false;
//}


