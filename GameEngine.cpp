#include "GameEngine.h"
#include "Player.h"



void GameEngine::setup(){
}

void GameEngine::run(){
	g = new Graphics(); 
	g->setup("ISHAB",WINDOW_WIDTH,WINDOW_HEIGHT,100,100);
	g->setCamera(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);
	camera = g->getCamera();
	player.setGraphics(g);
	player.setup();
	SDL_Texture* t = g->getTextureFromPath("Assets/testLevel.png");
	SDL_Rect src = g->makeRect(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);
	SDL_Rect dst = g->makeRect(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);
	SDL_Surface* s = g->getSurfaceFromPath("Assets/testLevel.png");
	a.setGraphics(g);
	a.setAreaSize(10000,1300);
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
							player.setXVel(4);
							break;	
						case SDLK_LEFT: 
							player.setFlipped(1);
							player.setState(RUNNING);
							player.setXVel(-4);
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
		//Update Camera: 
		SDL_Rect *cam;  
		cam = g-> getCamera();
		if(player.getXLoc()-cam->x > WINDOW_WIDTH - CAM_OFFSET_X){
			if(player.getXVel()>0)
				cam->x += player.getXVel();;

		}else if (player.getXLoc()-cam->x < CAM_OFFSET_X){
			if(player.getXVel()<0)
				cam->x += player.getXVel();
		}
		if(cam->x <= 0)
			cam->x = 0;
		if(cam->x >= 10000-WINDOW_WIDTH)
			cam->x = 10000-WINDOW_WIDTH;


		if(player.getYLoc()-cam->y > WINDOW_HEIGHT - CAM_OFFSET_Y){
			if(player.getYVel()>0)
				cam->y += player.getYVel();
		}else if (player.getYLoc()-cam->y < CAM_OFFSET_Y){
			if(player.getYVel()<0)
				cam->y += player.getYVel();
		}
		if(cam->y <= 0)
			cam->y = 0;
		if(cam->y >= 1300-WINDOW_HEIGHT)
			cam->y = 1300-WINDOW_HEIGHT;

		std::cout << cam->x << " " << cam->y << std::endl;

		player.updateFrame();

		std::cout << player.getXVel()<<std::endl;;
		//collision detection: 
		collisionInfo ci;
		ci = a.detectLegCollision(player);
		interpretCollision(ci);
		ci = a.detectHeadCollision(player);
		interpretCollision(ci);


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
}

void GameEngine::interpretCollision(collisionInfo ci){

	int movingUp = 0;
	int falling = 0;
	int movingSideWays = 0;
	
	
	//Get Player's velocity: 
	if(player.getYVel() <0)
		movingUp = 1;
	else if (player.getYVel() > 0)
		falling = 1;
	
	if(player.getXVel() >0 || player.getXVel() <0)
		movingSideWays = 1;


	if(ci.didCollide){
		//If the player is moving up: 
		switch(ci.collisionType){
			case BARRIER: 
				std::cout << "BARRIER!\n";
				if(falling){
					std::cout << "BARRIERFALLING\n";
					if(ci.bodySide == LEGS){
						player.setYVel(0);
						player.setYLocation(ci.y-player.getHeight());
						player.setGrounded(1);
						if(player.getXVel() == 0){
							player.setState(STANDING);
						}else{
							player.setState(RUNNING);
						}
					}
				}
				if (movingUp && !movingSideWays){
					std::cout << "BARRIERUP\n";
					if(ci.bodySide == HEAD){
						player.setYVel(0);
						player.setYLocation(ci.y+1);
					}
				}else if (movingSideWays){
					std::cout << "BARSIDE\n";
					if(ci.bodySide == LEGS){
						player.setYVel(0);
						player.setYLocation(ci.y-player.getHeight());
					}else if (ci.bodySide == HEAD){
						if(player.getMidX()<ci.x){
							//moving right
							player.setXLocation(ci.x-HEAD_WIDTH-14);
						}else{
							//moving left
							player.setXLocation(ci.x+1);
						}
						player.setXVel(0);
					}
				}
				break;
			case PLATFORM: 
				std::cout << "PLATFORM!\n";
				if(falling){
					std::cout << "PLATFALLING\n";
					if(ci.bodySide == LEGS){
						player.setYVel(0);
						player.setYLocation(ci.y-player.getHeight());
						player.setGrounded(1);
						if(player.getXVel() == 0){
							player.setState(STANDING);
						}else{
							player.setState(RUNNING);
						}
					}
				}else if (movingSideWays){
					std::cout << "PLATSIDE\n";
					if(ci.bodySide == LEGS){
						player.setYVel(0);
						player.setYLocation(ci.y-player.getHeight());
					}
						
				}
				break;
		}
	}else{
		player.setState(32);
		player.setGrounded(0);
	}
}

void GameEngine::close(){
	g->close();
}
