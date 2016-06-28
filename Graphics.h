/*
	John F. Lake, Jr. 
	Graphics Class
	Holds all info pertaining to rendering graphics on the screen. 
*/
#include <SDL2/SDL.h>
#include <SDL_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <string>
#include "Constants.h"
#ifndef __GRAPHICS__
#define __GRAPHICS__

class Graphics{
	public: 
		Graphics();
		void setup(const std::string title,int width, int height,int xLoc,int yLoc);
		void close();
		void clear(){SDL_RenderClear(renderer);}

		void render(SDL_Texture* t, SDL_Rect *src, SDL_Rect *dst);
		void renderWithFlip(SDL_Texture* t, SDL_Rect *src, SDL_Rect *dst,SDL_RendererFlip f);
		void renderFromLocation(SDL_Texture* t, SDL_Rect *src, int x, int y, int w, int h);
		void renderFromLocationWithFlip(SDL_Texture* t, SDL_Rect *src, int x, int y, int w, int h);
		void renderText(std::string text, int r, int g, int b,int x, int y, int w, int h);
		Uint32 getPixel(SDL_Surface*,int,int);

		void present(){SDL_RenderPresent(renderer);}
		void setCamera(int x, int y, int w, int h);
		void moveCamera(int,int);
		void displayRect(SDL_Rect r);
		void delay(int d){SDL_Delay(d);}
		
		SDL_Rect makeRect(int x, int y, int w, int h);
		SDL_Renderer* getRenderer(){return renderer;}
		SDL_Texture* getTextureFromPath(std::string);
		SDL_Surface* getSurfaceFromPath(std::string);
		SDL_Rect* getCamera(){return &camera;}

	private: 
		SDL_Renderer * renderer; 
		SDL_Window* window; 
		SDL_Rect camera;
};
#endif
