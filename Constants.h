#ifndef HEADERS_H
#define HEADERS_H
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <SDL2/SDL.h>
#include <iostream>
#include "Entity.h"
#include "Graphics.h"
#include "Sprite.h"
#include "StateManager.h"

typedef struct{
	int didCollide; 
	int collisionType;
	int collisionSide;
	int leftBound; 
	int rightBound; 
	int upBound; 
	int downBound;
	int bodySide;
	int x;
	int y;
	int result;
}collisionInfo;

//Sizes
#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 1000
#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 1000
#define START_DISTANCE 8
#define PLAYER_HEIGHT 131
#define PLAYER_WIDTH 120
#define PIXEL_GAP 10


//Directions
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4


//Physics: 
#define GRAVITY 1
#define JUMP_VEL -13
#define TERMINAL_VEL 10


//Collision Types: 
#define BARRIER 1
#define PLATFORM 2
#define LEGS 0
#define HEAD 1



//States: 
#define JUMPING 1
#define GROUNDED 2
#define STANDING 3
#define RUNNING 4


//Misc: 
#define NO 0
#define YES 1
#define WHITE 4294967295
#define RED 4294911488
#define BLACK 4278190080
#define HEAD_HEIGHT 69
#define HEAD_WIDTH 99
#define RUNNING_OFFSET 40
#define STANDING_OFFSET 40
#define LEG_OFFSET 120
#define CAM_OFFSET_X 300
#define CAM_OFFSET_Y 200

//Sprite Constants: 
#define DIST_BETWEEN_FRAMES 200
#define FRAME_HEIGHT 135
#define FRAME_WIDTH 120
#define FRAME_START_X 40
#define FRAME_OFFSET 2
#define RUN_NUM_FRAMES 12
#define STAND_NUM_FRAMES 10
#define RUN_START_Y 264
#define STAND_START_Y 65
#endif
