/*
	John F. Lake, Jr. 
	This is a class for management of the state of ISHAB.
*/

#include <string>

#ifndef __STATE_MANAGER__
#define __STATE_MANAGER__

class StateManager{
	public: 
		void loadGame(std::string saveFile);
		void saveGame(std::string saveFile);
		void setClock(int c){clock = c;}
		int getClock(){return clock;}
		void tickClock(){clock++;}
	private: 
		int clock;
		int level;
		int xLoc;
		int yLoc; 
		int cameraX;
		int cameraY;
};

#endif
