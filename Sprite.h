/*
	JFL
	Sprite class extends entity, yet stores motion/animation information
*/
#include "Entity.h"
#ifndef __SPRITE__
#define __SPRITE__
class Sprite: public Entity{
	public: 
		Sprite();
		void setNumFrames(int n){numFrames = n;}
		void setFrame(int f){currentFrame = f;}
		void setState(int s){state = s;}
		void setXVel(int x){xVel = x;}
		void setYVel(int y){yVel = y;}
		void setXAcc(int x){xAcc = x;}
		void setYAcc(int y){yAcc = y;}
		void setFlipped(int f){flipped = f;}
		void setGrounded(int g){grounded = g;}
		void update();

		int getState(){return state;}
		int getCurrentFrame(){return currentFrame;}
		int getNumFrames(){return numFrames;}
		int getXVel(){return xVel;}
		int getYVel(){return yVel;}
		int getXAcc(){return xAcc;}
		int getYAcc(){return yAcc;}
		int isFlipped(){return flipped;}
		int isGrounded(){return grounded;}

	protected: 
		int distBetweenFrames; 
		int currentFrame;
		int numFrames; 
		int frameStartX; 
		int frameStartY;
		int frameOffset;
		int frameHeight; 
		int frameWidth;
		int xVel;
		int yVel;
		int xAcc;
		int yAcc;
		int state;
		int grounded; 
		int flipped; 

};
#endif
