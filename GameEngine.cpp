#include "GameEngine.h"
#include "Player.h"



void GameEngine::setup(){



}


void GameEngine::run(){
	Player player;
	g = new Graphics(); 
	g->setup("ISHAB",WINDOW_WIDTH,WINDOW_HEIGHT,300,300);
	g->setCamera(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);
	camera = g->getCamera();
	player.setGraphics(g);
	player.setup();
	SDL_Surface* s = g->getSurfaceFromPath("Assets/testLevel.png");
	SDL_Texture* t = g->getTextureFromPath("Assets/testLevel.png");
	SDL_Rect src = g->makeRect(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);
	SDL_Rect dst = g->makeRect(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);
		
	Area a;
	a.setGraphics(g);
	a.setAreaSize(1300,1300);
	a.setBitmask(s);
//	a.printBitmask();



	
	
	int loop = 1;
	SDL_Event e;

	while(loop){
		
		while(SDL_PollEvent(&e)){
			switch(e.type){
				case SDL_KEYDOWN:
					switch(e.key.keysym.sym){
						case SDLK_q:
							loop = 0;
							break;
						case SDLK_SPACE:
							player.jump();
							player.setGrounded(0);
							break;	
						case SDLK_RIGHT: 
							player.setFlipped(0);
							player.setState(RUNNING);
							player.setXVel(2);
							break;	
						case SDLK_LEFT: 
							player.setFlipped(1);
							player.setState(RUNNING);
							player.setXVel(-2);
							break;	
											}
					break;
				case SDL_KEYUP:
					switch(e.key.keysym.sym){
						case SDLK_RIGHT: 
						case SDLK_LEFT: 
							player.setState(STANDING);
							player.setXVel(0);
							break;	
											}
					break;
			}
		}
		player.update();	
		player.updateFrame();


		//collision detection: 
		collisionInfo ci;
		ci.didCollide = 0;
		ci.x = 0;
		ci.y = 0;
		ci.collisionType = 1000;
		ci = a.detectCollision(player);
		if(ci.didCollide){
			if(ci.collisionDirection != UP){
				if(player.getXVel() == 0){
					player.setGrounded(1);;
					player.setState(STANDING);
				}else{
					player.setGrounded(1);;
					player.setState(RUNNING);
				}
				player.setYLocation(ci.y-player.getHeight());
			}
			else
				std::cout << " UP ";
		}else{
			player.setState(32);
			player.setGrounded(0);
		}
		SDL_Rect psrc = player.getSource();		
			
		g->clear();
		g->render(t,g->getCamera(),&dst);
		if(player.isFlipped())
			g->renderFromLocationWithFlip(player.getTexture(),&psrc,player.getXLoc(),player.getYLoc(),player.getWidth(),player.getHeight());
		else
			g->renderFromLocation(player.getTexture(),&psrc,player.getXLoc(),player.getYLoc(),player.getWidth(),player.getHeight());
		g->present();
		g->delay(30);
	}

/*
	StateManager sm;
	sm.loadGame("file.sav");

	for(int i = 0;i<40;i++)
		sm.tickClock();

	std::cout << sm.getClock();

	sm.saveGame("file.sav");

*/

	g->close();



}
