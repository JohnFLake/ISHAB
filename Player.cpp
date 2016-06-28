#include "Player.h"


Player::Player(){
	currentFrame = 0;
	frameHeight = 135;
	frameWidth = 120;
	distBetweenFrames = 200;
	frameStartX = 50;
}

void Player::setup(){
	SDL_Texture* ish = graphics->getTextureFromPath("Assets/Sprites/ish.png");
	setState(STANDING);
	setFlipped(0);
	setGrounded(1);
	setTexture(ish);
	setLocation(30,30);
	setWidth(120);
	setHeight(131);
}

void Player::update(){
	xVel += xAcc;
	yVel += yAcc;

	if(isGrounded()){
		yVel = 0;
	}
	xLoc += xVel;
	yLoc += yVel;

	//Update the camera: 
	SDL_Rect *cam;  
	cam = graphics-> getCamera();
	if(xLoc-cam->x > WINDOW_WIDTH - 200){
		cam->x += 5;
	}else if (xLoc-cam->x < 200){
		cam->x -= 5;
		if(cam->x <= 0)
			cam->x = 0;
	}

	if(yLoc-cam->y > WINDOW_HEIGHT - 100){
		cam->y += 5;
	}else if (yLoc-cam->y < 100){
		cam->y -= 5;
		if(cam->y <= 0)
			cam->y = 0;
	}
}


void Player::jump(){
	state = 432;
	yVel = -13;
}

void Player::setState(int s){
	state = s;
	switch(s){
		case STANDING: 
			distBetweenFrames = 200;
			numFrames = 10;
			frameWidth = 120;
			frameStartY = 65;
			frameStartX = 40;
			break;
		case RUNNING: 
			numFrames = 12;
			distBetweenFrames = 200;
			frameWidth = 120;
			frameStartY = 264;
			frameStartX = 40;
			break;
	}

}

void Player::updateFrame(){
	frameOffset++;

	if(frameOffset %3 == 0){
		currentFrame++; 
		if(currentFrame >= numFrames)
			currentFrame = 0;
		setSource(frameStartX + currentFrame * distBetweenFrames,frameStartY, frameWidth,frameHeight);
	}
	if(frameOffset>10)
		frameOffset = 0;
}


