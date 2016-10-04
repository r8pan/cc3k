#ifndef __GAME_H__
#define __GAME_H__
#include <iostream>
#include "cell.h"
#include "player.h"
using namespace std;



class Game {
protected:				 
	int _floorLength;    
	int _floorWidth;	  
	char **_TextDisplay;  // The text display.

public:
	//Player *_player;
	Game(int width, int length, char ** TextDisplay);
	~Game();
	
	Cell** floor ;  // The actual floor
	bool isLost();
	void print();
};

#endif


