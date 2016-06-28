/*
	JFL
	Area contains information about the background images, all locations, bitmask for detection, etc. 
*/


#include "Constants.h"
#include "Player.h"
#ifndef __AREA__
#define __AREA__

class Area {


	public: 
		collisionInfo detectCollision(Player e);
		void setBitmask(SDL_Surface*);
		void printBitmask();
		void setAreaSize(int,int);
		void setGraphics(Graphics *gr){g = gr;}
		
	private: 
		std::vector< std::vector<int> > bitmask;
		int width;
		int height;
		Graphics *g;
};
#endif 
