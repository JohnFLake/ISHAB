#include "Area.h"
#include "Player.h"
#include "Constants.h"

/*
	Go through the surface and populate the 2D vector with the pixels. 
*/
void Area::setBitmask(SDL_Surface *s){
	Uint32 pixel;	

	//For each column in the surface
	for(int col = 0;col < width/PIXEL_GAP;col++){

		//...and each row of pixels in the surface
		for(int row = 0;row < height/PIXEL_GAP;row++){

			//Get the pixel from the column (X), and the row (Y)
			pixel = g->getPixel(s,col*PIXEL_GAP,row*PIXEL_GAP);

			//If the pixel is NOT white, then count it as a boundary and update the 2D vector. 
			if(pixel == BLACK)
	//			std::cout << col << " " << row << " " << pixel << std::endl;
				bitmask[row][col] = BARRIER;
			else if (pixel == RED)
				bitmask[row][col] = PLATFORM;
		}
	}
}


/*
	Simply sets the size of the area bitmask
*/
void Area::setAreaSize(int w, int h){
	width = w;
	height = h;
	std::vector<int> bm;
/*	for(int i = 0;i<height;i++){
		for(int i = 0;i<width;i++){
			bm.push_back(0);
		}
		bitmask.push_back(bm);
	}
*/

	for(int i = 0;i<height/PIXEL_GAP;i++){
		for(int i = 0;i<width/PIXEL_GAP;i++){
			bm.push_back(0);
		}
		bitmask.push_back(bm);
	}
}



/*
	Used in debugging. 
*/
void Area::printBitmask(){
	for(int col = 0;col < width/PIXEL_GAP;col+=5){
		for(int row = 0;row < height;row+=5){
			if(bitmask[row][col] ==BARRIER)
				std::cout << "ROW: " << row << " COL: " << col << std::endl;
		}
	}
	for(int col = 0;col < width;col+=5){
		for(int row = 0;row < height;row+=5){
			if(bitmask[row][col] ==BARRIER)
				std::cout << "X";
			else 
				std::cout << ".";
		}
		std::cout << std::endl;
	}
}



/*
	just assembles the collision struct to be returned. 
*/
collisionInfo Area::interpretCollision(int type, int part,int x, int y,int up,int down,int left,int right, Player p){
	collisionInfo ci;
	ci.didCollide=1;
	ci.x = x;
	ci.y = y;
	ci.upBound = up;
	ci.downBound = down;
	ci.leftBound = left;
	ci.rightBound = right;
	ci.collisionType = type;
	if(part == LEGS){
		std::cout << "LEGS\n";
	}else{
		std::cout << "HEAD\n";
	}
	ci.bodySide = part;
	return ci;
}


/*
	Detects a collision between the player and the level
*/
collisionInfo Area::detectLegCollision(Player e){
	//Structure returned with collision information:
	collisionInfo ci;
	int x,y;
	//Setup the bounding box for the head: 
	int left = e.getXLoc()+RUNNING_OFFSET;
	int right = e.getXLoc()+e.getWidth() - RUNNING_OFFSET;
	int down = e.getYLoc()+e.getHeight();
	int up = e.getYLoc()+ LEG_OFFSET;
	//Check head collision at each corner of the head: 
	for(y = up; y <= down; y++){
		for(x = left;x <= right;x++){
			if(x % PIXEL_GAP == 0 && y % PIXEL_GAP == 0){
				//If there's a platform, return the proper struct for collision: 
				if(bitmask[y/PIXEL_GAP][x/PIXEL_GAP]==BARRIER){
					return interpretCollision(BARRIER,LEGS,x,y,up,down,left,right,e);
				}else if(bitmask[y/PIXEL_GAP][x/PIXEL_GAP]==PLATFORM){
					return interpretCollision(PLATFORM,LEGS,x,y,up,down,left,right,e);
				}
			}
		}
	}
	//If no collisions occur, just simply return. 
	ci.didCollide = 0;
	return ci;
}

collisionInfo Area::detectHeadCollision(Player e){
	//Structure returned with collision information:
	collisionInfo ci;
	int x,y,left,right;
	
	int up = e.getYLoc();
	int down = e.getYLoc()+HEAD_HEIGHT;
	if(e.getState() == STANDING){
		left = e.getXLoc();
		right = left+HEAD_WIDTH;
	}else{
		left = e.getXLoc()+13;
		right = left+HEAD_WIDTH;
	}
	//Check head collision at each corner of the head: 
	for(y = up; y <= down; y++){
		//Left and right side of head:
		for(x = left;x <= right;x++){
			if(x % PIXEL_GAP == 0 && y % PIXEL_GAP == 0){
				//If a pixel is a boundary on the bitmask, return the collision
				if(bitmask[y/PIXEL_GAP][x/PIXEL_GAP]==BARRIER){
					return interpretCollision(BARRIER,HEAD,x,y,up,down,left,right,e);
				}/* else if (bitmask[y][x] == PLATFORM){
					return interpretCollision(PLATFORM,HEAD,x,y,up,down,left,right,e);
				}*/
			}
		}
	}
	//If no collisions occur, just simply return. 
	ci.didCollide = 0;
	return ci;
}
