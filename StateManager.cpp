#include "StateManager.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>

std::string myText("some-text-to-tokenize");
void StateManager::saveGame(std::string saveFile){
	std::ofstream sf; 
	sf.open(saveFile);
	sf << "clock:" << clock;
	sf.close();
}


void StateManager::loadGame(std::string saveFile){
	std::ifstream sf; 
	std::string line;
	std::string token1;
	std::string token2;
	sf.open(saveFile);

	//if the file exists, open it: 
	if (sf.is_open()){

		//Go line by line through the file: 
		while ( getline (sf,line)){

			//Delimit each line and interpret the results
			std::istringstream iss(line);
			std::getline(iss, token1, ':');
			std::getline(iss, token2, ':');
				

			//Go through each possible field and update the game accordingly.
			if(token1.compare("clock")==0){
				clock = (int) stoi(token2);
			}
		
		}
	}	
	sf.close();
}
