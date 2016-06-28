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
		void setGrounded(int g){grounded = g;}
		int isGrounded(){return grounded;}
		void setFlipped(int f){flipped = f;}
		int isFlipped(){return flipped;}
		
	private: 
		int flipped; 
		int grounded; 
		int frameHeight; 
		int frameWidth; 
		int distBetweenFrames; 
		int frameStartX; 
		int frameStartY;

		
		

};
#endif
