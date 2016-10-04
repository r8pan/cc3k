#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>        //exit
#include <string>

using namespace std;


//Global constatnts 
int FLOOR_WIDTH = 25;
int FLOOR_LENGTH = 79;


bool convert(int &val, char*buffer){	//convert C string to integer
	stringstream ss(buffer);
	string temp;
	ss >> dec >> val;	// convert integer from buffer
	return ! ss.fail() &&   // conversion sucessful?
		!(ss >> temp);	// character after conversion all blanks?
}//convert


struct Floor {
	int row = 25, col = 79;
	char **grid;
	int level;
}floor[5];


void destroy (char** &f){  // free floor memory
	for (int r =0; r<25; r++) delete [] f[r];
	delete [] f;
}

//////MAIN

int main(int argc,char* argv[]) {


	uint32_t seed ;		// start with a psuedo random number
	bool infile_flag = false;
	ifstream layout;
	string fileName;

	for (int i =1; i<argc; i++){
		if (! convert((int &)seed, argv[i])){  // assign seed, else assign file
			fileName = argv[i];
			infile_flag = true;
		}
	}//for 
	//..................LOAD FLOORS FROM FILE..........................................................
	if (infile_flag){
		layout.open(fileName);
		for (int i=0; i<5; i++) {
			//build grid
			floor[i].grid = new char*[FLOOR_WIDTH];
			for (int r =0; r <FLOOR_WIDTH; r++){
				floor[i].grid[r] = new char[FLOOR_LENGTH];
			}
			floor[i].level = i+1;   //update floor level 
			//accumulate floor grid   
			char ch;     
			for (int h =0; h<FLOOR_WIDTH; h++){
				for (int l=0; l<FLOOR_LENGTH; l++){
					ch = layout.get();
					floor[i].grid[h][l] = ch;

				}
				layout.get();
			}
		}
		// file.close(fileName);
	}

	//....................START GAME.....................................................................
	while (true) { //
		bool restart_flag = false;
		//get player
		string my_player;
		cout <<"Welcome to ChamberCrawler3000!" << endl
			<<"What would you like to play as today?"<< endl
			<<"w) Wizard"<< endl
			<<"k) Knight"<< endl
			<<"s) Samurai"<< endl;



		string input;

		while(cin >> input){ //validate player
			//string ss;	
			//cin >>  ss;	
			stringstream ss(input);

			
			while(true){     // make it true just to get the game going
				ss  >> my_player;
				bool comp = (my_player == "k");
				cout << comp;
				if ((my_player != "k")||(my_player != "w")||(my_player !="s")){
					cout <<"Did not recognize input."<< endl;
				}
				 break; //exit when any of w/k/s is entered
			}//while

			cout << "You have chosen to play as a " <<  my_player << ". Good luck." <<endl;
			string my_move;
			int level = 0;
			for (; level < 6; level++) {
				//print new floor
				for (int r=0; r<FLOOR_WIDTH; r++){
					for (int c=0; c<FLOOR_LENGTH; c++){
						cout<< floor[level].grid[r][c];
					}
					cout << endl;
			        }	

				//	initialize game

				//	call game.print  


				//interactive game moves

				//while (! restart_flag ){
					cout << "What will you do?" << endl;
					ss >> my_move; 

					//quit 
					string  yes_no;
					if (my_move == "q"){
						cout << "Are you sure you want to quit? (y/n)" << endl;
						while(true){ //invalid input
							ss >> yes_no;
							if ((yes_no == "y")||(yes_no == "n")){
								break;
							}
							cout <<"Did not recognize input."<< endl;
						}//while
						if ( yes_no == "y" ) {
							cout << "You have chosen to exit. At least you tried." << endl;
							exit(0);  // exit main 
						} 
					}// else continue game/ exit if 

					//restart
					else if (my_move == "r"){
						cout << "Are you sure you want to restart? (y/n)" << endl;
						while(true){ //invalid input
							ss >> yes_no;

							if ((yes_no == "y")||(yes_no == "n")){
								break;
							}
							cout <<"Did not recognize input."<< endl;
						}//while
						if ( yes_no == "y" ) {
							restart_flag = true;
							break; //exit while
						}
					}

					//all other moves that are not quit or restart
					else {
					    while (true) {
						cout << "What will you do?" << endl;
						char action;
						char dir1;
						char dir2;
						cin << action;
						string dir;
						if (action == 'a') {
						    cin << dir1;
						    cin << dir2;
						    dir = dir1 + dir2;
						    if (dir !="nw" || dir != "no" || dir != "ne" || dir != "we" || dir != "ea" || dir != "sw" || dir != "so" || dir != "se") {
							cout << "Can't recognize input." << endl;
							continue;
						    }
						    else {
							my_player.attack(dir);
						    }
						}
						else if (action == 'u') {
						    cin >> dir1;
						    cin >> dir2;
						    dir = dir1 + dir2;
						    if (dir !="nw" || dir != "no" || dir != "ne" || dir != "we" || dir != "ea" || dir != "sw" || dir != "so" || dir != "se") {
							cout << "Can't recognize input." << endl;
							continue;
						    }
						    else {
							try {
							    my_player.drink();
							    if (my_player.hp() <= 0) {
								throw 88;
							    }
							}
						    }
						}
						else if (action == 'n' || action == 'e' || action == 's' || action == 'w') {
						    dir1 = action;
						    cin >> dir2;
						    dir = dir1 + dir2;
						    my_player.move(dir);
						    if (my_player.board->floor[x()][y()].getType() == staircase) {
							break;
						    }
						}
						for (int i = 0; i < 25; i++) {
						    for (int j = 0; j < 79; j++) {
							if (dynamic_cast<Charater*>(new_game->floor[i][j]._contents)->getCharacterType() == enemy) {
							    try {
								dynamic_cast<Charater*>(new_game->floor[i][j]._contents).tick();
								if (my_player.hp() <= 0) {
								    throw 88;
								}
							    }
							}
						    }
						}					    
					    }
					}
			//	}//while restart

				destroy(floor[level].grid);

				if (level == 6){
					cout << "You Won!" << endl;
				}
			}//for levels

		}

	}
	catch (int i) {
	    exit[EXIT_FAILURE];
	}

}//main
