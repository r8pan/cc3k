#include "cell.h"
#include "player.h"
#include "game.h"

class Cell;

Game::Game(int rows, int cols, char** TextDisplay){
	_floorWidth = rows;
	_floorLength = cols;
	//_player = player;
	_TextDisplay = TextDisplay;


	//create memory for floor
	floor = new Cell*[_floorWidth];	//25 Cell rows per floor
	for (int r=0; r<_floorWidth; r++){
		floor[r] = new Cell[_floorLength];  //79 Cell columns per floor 
	}
	//build floor
	for(int i=0; i<_floorWidth; i++){
		for(int j=0; j < _floorLength; j++){
			floor[i][j].display(_TextDisplay[i][j]);
			floor[i][j].setCoords(i,j);
			floor[i][j].setChamber(i,j);
			//add neighbours
			/*
			   if (i != 0) && (j != 0){// add top_left(nw)
			   floor[i][j].addneighbour(&floor[i-1][j-1];
			   }
			   if (i != 24) && (j != 0){ //add bottom_left(sw)
			   floor[i][j].addneighbour(&floor[i+1][j-1];
			   }
			   if (i != 0) && (j != 0){// add top_right(ne)
			   floor[i][j].addneighbour(&floor[i-1][j+1];
			   }
			   if (i != 24) && (j != 0){ //add bottom_right(se)
			   floor[i][j].addneighbour(&floor[i+1][j+1];
			   }
			   if (j != 0){ // add left(we)
			   floor[i][j].addneighbour(&floor[i][j-1];
			   }
			   if (j != 78){ // add right(ea)
			   floor[i][j].addneighbour(&floor[i][j+1];
			   }
			   if (i != 0){  // add top(no)
			   floor[i][j].addneighbour(&floor[i-1][j];
			   }
			   if (i != 24){ // add bottom(so)
			   floor[i][j].addneighbour(&floor[i][j-1];
			   }
			 */
		}// inner for
	}//for
}//game


Game::~Game(){   // destructor
	for (int i=0; i<_floorWidth; i++) 
		delete [] floor[i];
	delete [] floor;
}

//int Game::getTurns() { //
//	return turns;
//}

//bool Game::isWon( ) { //
//	if (( player->hp() > 0) && (board->level == 6)){
//		return true;
//	}
//	else return false;
//}

bool Game::isLost() { //
    return false;
}

void Game::print() {// print floor
	for (int r = 0; r < _floorWidth; r++) {
		for (int c =0; c<_floorLength; c++){
				cout <<  floor[r][c].display();		
		}
	}
}

             
