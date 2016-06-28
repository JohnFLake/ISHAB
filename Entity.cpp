#include "Entity.h"


void Entity::setLocation(int x, int y){
	xLoc = x;
	yLoc = y;
}
void Entity::move(int x, int y){
	xLoc += x;
	yLoc += y;
}
void Entity::render(){
	dst = graphics->makeRect(xLoc,yLoc,width,height);
	graphics->renderFromLocation(tex,&src,xLoc,yLoc,width,height);
}

void Entity::setTextureFromPath(std::string path){
	tex = graphics->getTextureFromPath(path);
}


void Entity::setSource(int x, int y, int w, int h){
	SDL_Rect r; 
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	src = r;
}
