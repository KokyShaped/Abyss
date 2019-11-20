#include <stddef.h>
#include "definitions.h"
#include "vector.h"
#include <assert.h>
#include <stdio.h>
#include "random.h"
#include "resources.h"
#include <SDL2/SDL.h>
#include "error.h"
#include "graphics.h"
#include "entity.h"
#include "input.h"
#include <SDL2/SDL_ttf.h>


int main(){

	randomize();
//SDL init....

	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		logSDLError("INIT");	
	}

	if (TTF_Init() != 0){
		logSDLError("TTF");
	}


	SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (win == NULL){
		logSDLError("WINDOW");
		SDL_Quit();
		return 1;
	}

	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL){
		SDL_DestroyWindow(win);
		logSDLError("RENDERER");
		SDL_Quit();
		return 1;
	}



	//resources and stufff
	IoData* data = initIoData(ren);

	EntityManager* manager = createEntityManager();
	initEntityManager(manager, data);
	initUI(manager, ren);


	Room* aux = createRoom();
	initRoom(aux);
	addRoom(manager, aux);

	//game loop

	bool quit = false;
	while (!quit){
		
		//INPUT
		handleInput(manager, &quit);

		updateCameraOffset(manager);
		
		//RENDER
		SDL_RenderClear(ren);

		drawCurrentRoom(manager, ren);
		drawPlayer(manager, ren);
		renderLabelColumn(ren, manager->column);

		SDL_RenderPresent(ren);
		SDL_Delay(16);
	}



	//CLEAN UP
	freeIoData(data);
	printf("doneeee\n");
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	printf("doneeee\n");
}