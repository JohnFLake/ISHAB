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
		collisionInfo detectHeadCollision(Player);
		collisionInfo detectLegCollision(Player);
		collisionInfo detectCollision(Sprite);
		void setBitmask(SDL_Surface*);
		void printBitmask();
		void setAreaSize(int,int);
		void setGraphics(Graphics *gr){g = gr;}
	private: 
		collisionInfo interpretCollision(int,int,int,int,int,int,int,int,Player p);
		int width;
		int height;
		Graphics *g;

		//2D Vector of boundaries for area: 
		std::vector< std::vector<int> > bitmask;
};
#endif 
