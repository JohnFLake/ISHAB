/*
	JFL
	Ishmael
*/
#include "Sprite.h"

#ifndef __PLAYER__
#define __PLAYER__

class Player: public Sprite{
	public:
		Player();
		void jump();
		void action();
		void updateFrame();
		void update();
		void setup();
		void setState(int s);
		int getMidX(){return midX;}
						
	private: 
		int midX; 
		

};
#endif
