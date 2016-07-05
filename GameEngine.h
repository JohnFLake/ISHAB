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
		void setArea(Area area);
		void interpretCollision(collisionInfo);
	private: 
		Player player;
		SDL_Rect* camera;
		Graphics* g;
		StateManager sm;
		Area a;
};
#endif
