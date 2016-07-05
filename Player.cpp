#include "Player.h"

Player::Player(){
	frameHeight = FRAME_HEIGHT;
	frameOffset = 0;
	frameWidth = FRAME_WIDTH;
	distBetweenFrames = DIST_BETWEEN_FRAMES;
	frameStartX = FRAME_START_X;
	yVel = 0;
	xVel = 0;
	xLoc = 0;
	yLoc = 0;
	midX = 0;
	xAcc = 0;
	yAcc = GRAVITY;
}

void Player::setup(){
	SDL_Texture* ishmael = graphics->getTextureFromPath("Assets/Sprites/ish.png");
	setState(STANDING);
	setFlipped(NO);
	setGrounded(YES);
	setTexture(ishmael);

	//Location will be set based on the area the player is in. 
	setLocation(30,30);
	setWidth(PLAYER_WIDTH);
	setHeight(PLAYER_HEIGHT);
}

void Player::update(){
	xVel += xAcc;
	yVel += yAcc;
	if(yVel >= TERMINAL_VEL)
		yVel = TERMINAL_VEL;

	if(isGrounded()){
		yVel = 0;
	}
	xLoc += xVel;
	yLoc += yVel;

	midX = xLoc + width/2;

}


void Player::jump(){
	state = JUMPING;
	yVel = JUMP_VEL;
}

void Player::setState(int s){
	Sprite::setState(s);
	switch(s){
		case STANDING: 
			numFrames = STAND_NUM_FRAMES;
			frameStartY = STAND_START_Y;
			break;
		case RUNNING: 
			numFrames = RUN_NUM_FRAMES;
			frameStartY = RUN_START_Y;
			break;
	}
}



void Player::updateFrame(){
	//Offset used to delay animation
	frameOffset++;
	if(frameOffset %FRAME_OFFSET == 0){
		currentFrame++; 
		if(currentFrame >= numFrames)
			currentFrame = 0;
		setSource(frameStartX + currentFrame * distBetweenFrames,frameStartY, frameWidth,frameHeight);
	}
	if(frameOffset>10)
		frameOffset = 0;
}
