#include "Sprite.h"

Sprite::Sprite(){
	yAcc = GRAVITY;
}
void Sprite::update(){
	xVel += xAcc;
	yVel += yAcc;
	xLoc += xVel;
	yLoc += yVel;
}
