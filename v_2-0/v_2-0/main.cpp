#include "SDL.h"
#include "iostream"
#include "SDL_ttf.h"
using namespace std;

const int BALL_X=390;
const int BALL_Y=290;

Uint32 white;

SDL_Event e;
SDL_Rect player;
SDL_Rect ai;
SDL_Rect ball;

SDL_Window	*screen=SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
SDL_Renderer * rend=SDL_CreateRenderer(screen, -1, 0);
Uint32 pFormat=SDL_GetWindowPixelFormat(screen);


void loadGame(){
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	player.x=20;
	player.y=0;
	player.h=150;
	player.w=10;

	ai.x=760;
	ai.y=0;
	ai.h=150;
	ai.w=10;

	ball.x=BALL_X;
	ball.y=BALL_Y;
	ball.w=20;
	ball.h=20;

	white=SDL_MapRGB(pFormat,255,255,255);
}

void quit(){
	TTF_Quit();
	SDL_Quit();
}

void eventE(){

}

void screenS(){

	SDL_FillRect(surf,NULL,0);

	SDL_FillRect(surf,&player,white);
	SDL_FillRect(surf,&ai,white);
	SDL_FillRect(surf,&ball,white);
	
	SDL_RenderPresent(rend);
}

int main(int argc, char* args[]){	
	bool run=true;

	loadGame();
	while(run){
		SDL_PollEvent(&e);
		if(e.type==SDL_QUIT){
			run=false;
		}
		eventE();
		screenS();
	}
	quit();
	return 0;
}