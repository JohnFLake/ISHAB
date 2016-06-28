#include "Sprite.h"

Sprite::Sprite(){
	yAcc = GRAVITY;
}


void Sprite::update(){
	xVel += xAcc;
	yVel += yAcc;

	if(state == STANDING){
		std::cout << "STANDING";
		yVel = 0;
	}
	xLoc += xVel;
	yLoc += yVel;
}
