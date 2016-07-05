/*
	JFL
	An entity is simply an object that has a location, size, and texture
*/
#include "Graphics.h"
#ifndef __ENTITY__
#define __ENTITY__
class Entity{
	public: 
		Graphics *getGraphics(){return graphics;}
		SDL_Texture* getTexture(){return tex;}
		SDL_Rect getDst(){return dst;}
		SDL_Rect getSource(){return src;}
		int getXLoc(){return xLoc;}
		int getYLoc(){return yLoc;}
		int getWidth(){return width;}
		int getHeight(){return height;}

		void setWidth(int w){width=w;}
		void setHeight(int h){height=h;}
		void setLocation(int,int);
		void setXLocation(int x){xLoc = x;}
		void setYLocation(int y){yLoc = y;}
		void setGraphics(Graphics *g){graphics = g;}
		void setTexture(SDL_Texture * t){tex = t;}
		void setTextureFromPath(std::string);
		void setSource(int,int,int,int);
		void setDst(int,int,int,int);

		void render();
		void move(int,int);
		void moveX(int x){xLoc+=x;}
		void moveY(int y){yLoc+=y;}
	protected: 
		Graphics *graphics;
		SDL_Texture* tex;
		SDL_Rect src; 
		SDL_Rect dst;
		int xLoc;
		int yLoc;
		int width;
		int height;
};
#endif
