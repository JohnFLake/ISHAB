#include "Area.h"
#include "Player.h"



void Area::setBitmask(SDL_Surface *s){
	Uint32 pixel;	
	for(int col = 0;col < width;col++){
		for(int row = 0;row < height;row++){
			pixel = g->getPixel(s,col,row);
			if(pixel != WHITE)
				bitmask[row][col] = 1;
		}
	}
}

void Area::setAreaSize(int w, int h){
	width = w;
	height = h;
	std::vector<int> bm;

	for(int i = 0;i<height;i++){
		for(int i = 0;i<width;i++){
			bm.push_back(0);
		}
		bitmask.push_back(bm);
	}
}



void Area::printBitmask(){
	
	for(int col = 0;col < width;col++){
		for(int row = 0;row < height;row++){
			
			if(bitmask[row][col] ==1)
				std::cout << "ROW: " << row << " COL: " << col << std::endl;

		}
	}
	for(int col = 0;col < width;col++){
		for(int row = 0;row < height;row++){
			
			if(bitmask[row][col] ==1)
				std::cout << "X";
			else 
				std::cout << ".";

		}
		std::cout << std::endl;
	}

}


collisionInfo Area::detectCollision(Player e){
	//scanning area is only immediately around the object, to reduce computational complexity: 
	//Eventually this will evolve to be more than just boundary collision
	collisionInfo ci;
	int left = e.getXLoc();
	int right = e.getXLoc()+e.getWidth();;
	int up = e.getYLoc();
	int down = e.getYLoc()+75;
	int x,y;

	
	//Check head collision at each corner of the head: 
	for(y = up; y <= down; y++){
		for(x = left;x <= right;x++){
			if(bitmask[y][x]==1){
				ci.didCollide=1;
				if(e.getYVel() <0)
					ci.collisionDirection = UP;
				else if(e.getYVel() >0)
					ci.collisionDirection = DOWN;
				else if(e.getXVel() <0)
					ci.collisionDirection = LEFT;
				else if(e.getXVel() >0)
					ci.collisionDirection = RIGHT;

				ci.x = x;
				ci.y = y;

				//Collision Type: 
				if(bitmask[down][right] && bitmask[down][left]){
					ci.collisionType = GROUND;
				} else if (bitmask[down][right] && ! bitmask[down][left]){
					ci.collisionType = SLOPERIGHT;
				} else if (!bitmask[down][right] &&  bitmask[down][left]){
					ci.collisionType = SLOPELEFT;
				}
				
				return ci;
			}
		}
	}


	if(e.getState() == RUNNING){
		left = e.getXLoc()+50;
		right = e.getXLoc()+e.getWidth() - 50;
	}else{
		left = e.getXLoc()+35;
		right = e.getXLoc()+e.getWidth() - 35;
	}
	down = e.getYLoc()+e.getHeight();
	up = e.getYLoc()+ 100;

	
	//Check head collision at each corner of the head: 
	for(y = up; y <= down; y++){
		for(x = left;x <= right;x++){
			if(bitmask[y][x]==1){
				ci.didCollide=1;
				if(e.getYVel() <0)
					ci.collisionDirection = UP;
				else if(e.getYVel() >0)
					ci.collisionDirection = DOWN;
				else if(e.getXVel() <0)
					ci.collisionDirection = LEFT;
				else if(e.getXVel() >0)
					ci.collisionDirection = RIGHT;

				ci.x = x;
				ci.y = y;

				//Collision Type: 
				if(bitmask[down][right] && bitmask[down][left]){
					ci.collisionType = GROUND;
				} else if (bitmask[down][right] && ! bitmask[down][left]){
					ci.collisionType = SLOPERIGHT;
				} else if (!bitmask[down][right] &&  bitmask[down][left]){
					ci.collisionType = SLOPELEFT;
				}
				
				return ci;
			}
		}
	}


	ci.didCollide = 0;
	return ci;
}
