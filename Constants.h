//Put all of the includes here.
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
	int collisionDirection;
	int x;
	int y;
}collisionInfo;

//Sizes
#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 1000
#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 1000
#define START_DISTANCE 8

#define WHITE 4294967295

//Directions
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4


//Physics: 
#define GRAVITY 1


//Collision Types: 
#define GROUND 0
#define SLOPELEFT 1 
#define SLOPERIGHT 2


//States: 
#define JUMPING 1
#define GROUNDED 2
#define STANDING 3
#define RUNNING 4

#endif
