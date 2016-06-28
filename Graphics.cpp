#include "Graphics.h"
#include "Constants.h"
#include <string>
#include <iostream>

Graphics::Graphics(){
	setCamera(0,0,0,0);
}


Uint32 Graphics::getPixel( SDL_Surface *surface, int x, int y ){
    //Convert the pixels to 32 bit
    Uint32 *pixels = (Uint32 *)surface->pixels;
    
    //Get the requested pixel
    return pixels[ ( y * surface->w ) + x ];
}


void Graphics::renderText(std::string text, int r, int g, int b, int x, int y, int w,int h){
	TTF_Font *font = TTF_OpenFont("/Library/Fonts/Georgia.ttf",12);

	if(font == NULL)
		return;
	SDL_Color text_color = {r,g,b};
	const char* text_c = text.c_str();
	SDL_Surface *s = TTF_RenderText_Solid(font,text_c,text_color);

	SDL_Texture* t = SDL_CreateTextureFromSurface(renderer,s);
	SDL_Rect dst = makeRect(x,y,w,h);
	SDL_RenderCopy(renderer,t,NULL,&dst);

	//Free stuff up
	TTF_CloseFont(font);
	SDL_FreeSurface(s);
	SDL_DestroyTexture(t);


}

SDL_Surface* Graphics::getSurfaceFromPath(std::string path){
	SDL_Surface* loadSurf = IMG_Load(path.c_str());
	return loadSurf;
}
SDL_Texture* Graphics::getTextureFromPath(std::string path){
	SDL_Texture* tex = NULL;
	SDL_Surface* loadSurf = IMG_Load(path.c_str());
	tex = SDL_CreateTextureFromSurface(renderer,loadSurf);
	SDL_FreeSurface(loadSurf);
	return tex;
}



void Graphics::setup(const std::string title,int width, int height,int xLoc,int yLoc){
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	window = SDL_CreateWindow(title.c_str(),xLoc,yLoc,width,height,0);
	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
}

void Graphics::close(){
	SDL_DestroyRenderer(renderer); 
	SDL_DestroyWindow(window); 
	SDL_Quit(); 
	TTF_Quit();
}

void Graphics::render(SDL_Texture * t, SDL_Rect * src, SDL_Rect * dst){
	SDL_RenderCopy(renderer,t,src,dst);
}

void Graphics::renderWithFlip(SDL_Texture * t, SDL_Rect * src, SDL_Rect * dst,SDL_RendererFlip flip){
	SDL_RenderCopyEx(renderer,t,src,dst,0,0,flip);
}

SDL_Rect Graphics::makeRect(int x, int y, int w, int h){
	SDL_Rect ret; 
	ret.x = x;
	ret.y = y;
	ret.w = w;
	ret.h = h;
	return ret;
}

void Graphics::displayRect(SDL_Rect r){
	std::cout << "Rect:\n";
	std::cout << "X: " << r.x << std::endl;
	std::cout << "Y: " << r.y << std::endl;
	std::cout << "W: " << r.w << std::endl;
	std::cout << "H: " << r.h << std::endl;
}

void Graphics::setCamera(int x, int y, int w, int h){
	camera.x = x;
	camera.y = y;
	camera.w = w;
	camera.h = h;
}

void Graphics::moveCamera(int x, int y){
	camera.x += x;
	camera.y += y;
	if(camera.x <= 0){
		camera.x = 0;
	}
	if(camera.y <= 0){
		camera.y= 0;
	}
}


void Graphics::renderFromLocation(SDL_Texture* t, SDL_Rect * src, int x, int y, int w, int h){
	SDL_Rect dst = makeRect(x-camera.x,y-camera.y,w,h);
	render(t,src,&dst);
}

void Graphics::renderFromLocationWithFlip(SDL_Texture* t, SDL_Rect * src, int x, int y, int w, int h){
	SDL_Rect dst = makeRect(x-camera.x,y-camera.y,w,h);
	renderWithFlip(t,src,&dst,SDL_FLIP_HORIZONTAL);
}
