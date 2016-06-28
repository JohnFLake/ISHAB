/*
	JFL
	Manages game assets, transitions, etc. 
*/


#include "Constants.h"
#include "Area.h"
#ifndef __GAME_ENGINE__
#define __GAME_ENGINE__


class GameEngine{

	public: 
		void setup();
		void run();
		void close();

	private: 
		SDL_Rect* camera;
		Graphics* g;
		StateManager sm;
		



};


#endif
