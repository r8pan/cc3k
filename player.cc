#include "player.h"
#include <iostream>

#include <string>

using namespace std;

class Enemy;

Player::Player(playerType plType, bool v, characterType cType, int x, int y, GOType gType) : Character(cType, x, y, gType) {
    display('@');
    visible = true;
    me(true);
    plt = plType;
    if (plt == knight) {
	hp(100);
	atk(50);
	def(50);
    }
    else if (plt == wizard) {
	hp(60);
	atk(25);
	def(0);
    }
    else {
	hp(80);
	atk(50);
	def(15);
	visible = false;
    }
}
/*
void Player::drink(Potion &p) {
    if (p.getPotionType() == RH) {
	hp(hp()+30);
    }
    else if (p.getPotionType() == BA) {
	atk(atk()+10);
    }
    else if (p.getPotionType() == BD) {
	def(def()+10);
    }
    else if (p.getPotionType() == PH) {
	hp(hp()-15);
	if (hp() <= 0) {
	    board->isWon();
	}
    }
    else if (p.getPotionType() == WA) {
	atk(atk()-5);
    }
    else {
	def(def()-5);
    }
    delete p;
    board->floor[row][col]->_contents = NULL;
    board->floor[row][col]->_display = '.';
    board->floor[row][col]->_occupied = false;
}
*/
void Player::setGold(int d) {
    gold = d;
}

int Player::getGold() {
    return gold;
}

void Player::attacked(int health) {
    hp(hp()-health);
}

void Player::gainHP() {
    hp(hp()+5);
}

void Player::collectGold(int d) {
    setGold(getGold()+d);
}

void Player::move(string dir) {
    if (dir == "nw") {
	if (board->floor[x()-1][y()-1].occupied) {
	    cout << "You can't move in that direction." << endl;
	    
	}
	else {
	    addLocation(&board->floor[x()-1][y()-1]);
	    board->floor[x()][y()]._contents = NULL;
	    board->floor[x()][y()].display('.');
	    board->floor[x()][y()].occupied = false;
	    board->floor[x()-1][y()-1].addGameObject(this);
	    cout << "You moved northwest." << endl;
	}
    }
    else if (dir == "no") {
	if (board->floor[x()][y()-1].occupied) {
	    cout << "You can't move in that direction." << endl;
	    
	}
	else {
	    addLocation(&board->floor[x()][y()-1]);
	    board->floor[x()][y()]._contents = NULL;
	    board->floor[x()][y()].display('.');
	    board->floor[x()][y()].occupied = false;
	    board->floor[x()][y()-1].addGameObject(this);
	    cout << "You moved north." << endl;
	}
    }
    else if (dir == "ne") {
	if (board->floor[x()+1][y()-1].occupied) {
	    cout << "You can't move in that direction." << endl;
	  
	}
	else {
	    addLocation(&board->floor[x()+1][y()-1]);
	    board->floor[x()][y()]._contents = NULL;
	    board->floor[x()][y()].display('.');
	    board->floor[x()][y()].occupied = false;
	    board->floor[x()+1][y()-1].addGameObject(this);
	    cout << 'You moved northeast." << endl;
	}
    }
    else if (dir == "we") {
	if (board->floor[x()-1][y()].occupied) {
	    cout << "You can't move in that direction." << endl;

	}
	else {
	    addLocation(&board->floor[x()-1][y()]);
	    board->floor[x()][y()]._contents = NULL;
	    board->floor[x()][y()].display('.');
	    board->floor[x()][y()].occupied = false;
	    board->floor[x()-1][y()].addGameObject(this);
	    cout << 'You moved west." << endl;
	}
    }
    else if (dir == "ea") {
	if (board->floor[x()+1][y()].occupied) {
	    cout << "You can't move in that direction." << endl;
	  
	}
	else {
	    addLocation(&board->floor[x()+1][y()]);
	    board->floor[x()][y()]._contents = NULL;
	    board->floor[x()][y()].display('.');
	    board->floor[x()][y()].occupied = false;
	    board->floor[x()+1][y()].addGameObject(this);
	    cout << 'You moved east." << endl;
	}
    }
    else if (dir == "sw") {
	if (board->floor[x()-1][y()+1].occupied) {
	    cout << "You can't move in that direction." << endl;
	    
	}
	else {
	    addLocation(&board->floor[x()-1][y()+1]);
	    board->floor[x()][y()]._contents = NULL;
	    board->floor[x()][y()].display('.');
	    board->floor[x()][y()].occupied = false;
	    board->floor[x()-1][y()+1].addGameObject(this);
	    cout << 'You moved southwest." << endl;
	}
    }
    else if (dir == "so") {
	if (board->floor[x()][y()+1].occupied) {
	    cout << "You can't move in that direction." << endl;
	    
	}
	else {
	    addLocation(&board->floor[x()][y()+1]);
	    board->floor[x()][y()]._contents = NULL;
	    board->floor[x()][y()].display('.');
	    board->floor[x()][y()].occupied = false;
	    board->floor[x()][y()].addGameObject(this);
	    cout << 'You moved south." << endl;
	}
    }
    else if (dir == "se") {
	if (board->floor[x()+1][y()+1].occupied) {
	    cout << "You can't move in that direction." << endl;

	}
	else {
	    addLocation(&board->floor[x()+1][y()+1]);
	    board->floor[x()][y()]._contents = NULL;
	    board->floor[x()][y()].display('.');
	    board->floor[x()][y()].occupied = false;
	    board->floor[x()+1][y()+1].addGameObject(this);
	    cout << 'You moved southeast." << endl;
	}
    }
}

void Player::attack(string dir) {
    if (dir == "nw") {
	if (!board->floor[x()-1][y()-1].occupied || (board->floor[x()-1][y()-1].occupied && board->floor[x()-1][y()-1]._contents->getGOType() == item)) {
	    cout << "You can't attack in that direction." << endl;
	}
	else if (board->floor[x()-1][y()-1]._contents->getGOType() == character) {
	    dynamic_cast<Enemy*>(board->floor[x()-1][y()-1]._contents)->attacked(this->atk());
	}
    }
    else if (dir == "no") {
	if (!board->floor[x()][y()-1].occupied || (board->floor[x()][y()-1].occupied && board->floor[x()][y()-1]._contents->getGOType() == item)) {
	    cout << "You can't attack in that direction." << endl;
	}
	else if (board->floor[x()][y()-1]._contents->getGOType() == character) {
	    dynamic_cast<Enemy*>(board->floor[x()][y()-1]._contents)->attacked(this->atk());
	}
    }
    else if (dir == "ne") {
	if (!board->floor[x()+1][y()-1].occupied || (board->floor[x()+1][y()-1].occupied && board->floor[x()+1][y()-1]._contents->getGOType() == item)) {
	    cout << "You can't attack in that direction." << endl;
	}
	else if (board->floor[x()+1][y()-1]._contents->getGOType() == character){
	    dynamic_cast<Enemy*>(board->floor[x()+1][y()-1]._contents)->attacked(this->atk());
	}
    }
    else if (dir == "we") {
	if (!board->floor[x()-1][y()].occupied || (board->floor[x()-1][y()-1].occupied && board->floor[x()-1][y()]._contents->getGOType() == item)) {
	    cout << "You can't attack in that direction." << endl;
	}
	else if (board->floor[x()-1][y()]._contents->getGOType() == character) {
	    dynamic_cast<Enemy*>(board->floor[x()-1][y()-1]._contents)->attacked(this->atk());
	}
    }
    else if (dir == "ea") {
	if (!board->floor[x()+1][y()].occupied || (board->floor[x()+1][y()].occupied && board->floor[x()+1][y()]._contents->getGOType() == item)) {
	    cout << "You can't attack in that direction." << endl;
	}
	else if (board->floor[x()+1][y()]._contents->getGOType() == character) {
	    dynamic_cast<Enemy*>(board->floor[x()+1][y()]._contents)->attacked(this->atk());
	}
    }
    if (dir == "sw") {
	if (!board->floor[x()-1][y()+1].occupied || (board->floor[x()-1][y()+1].occupied && board->floor[x()-1][y()+1]._contents->getGOType() == item)) {
	    cout << "You can't attack in that direction." << endl;
	}
	else if (board->floor[x()-1][y()+1]._contents->getGOType() == character) {
	    dynamic_cast<Enemy*>(board->floor[x()-1][y()+1]._contents)->attacked(this->atk());
	}
    }
    else if (dir == "so") {
	if (!board->floor[x()][y()+1].occupied || (board->floor[x()][y()+1].occupied && board->floor[x()][y()+1]._contents->getGOType() == item)) {
	    cout << "You can't attack in that direction." << endl;
	}
	else if (board->floor[x()][y()+1]._contents->getGOType() == character) {
	    dynamic_cast<Enemy*>(board->floor[x()][y()+1]._contents)->attacked(this->atk());
	}
    }
    if (dir == "se") {
	if (!board->floor[x()+1][y()+1].occupied || (board->floor[x()+1][y()+1].occupied && board->floor[x()+1][y()+1]._contents->getGOType() == item)) {
	    cout << "You can't attack in that direction." << endl;
	}
	else if (board->floor[x()+1][y()+1]._contents->getGOType() == character) {
	    dynamic_cast<Enemy*>(board->floor[x()+1][y()+1]._contents)->attacked(this->atk());
	}
    }    
    else {
	cout << "Did not recognize input." << endl;
    }
}

void Player::resetAD() {
    if (plt == knight) {
	atk(50);
	def(50);
    }
    else if (plt == wizard) {
	atk(25);
	def(0);
    }
    else {
	atk(50);
	def(15);
    }
}











    
