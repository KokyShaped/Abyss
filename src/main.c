#include <stddef.h>
#include "definitions.h"
#include <assert.h>
#include <stdio.h>
#include "random.h"
#include "resources.h"
#include <SDL2/SDL.h>
#include "error.h"
#include "graphics.h"
#include "entity.h"




int main(){

//SDL init....

	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		logSDLError("INIT");	
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

	EntityManager* entityManager = createEntityManager();
	initEntityManager(entityManager, data);

	Room* aux = createRoom();
	initRoom(aux);
	addRoom(entityManager, aux);

	//game loop
	for (int i = 0; i < 10; i++){
		
		SDL_RenderClear(ren);

		drawCurrentRoom(entityManager, ren);
		
		SDL_RenderPresent(ren);
		printf("Pass %d done\n", i);
		SDL_Delay(500);
	}








	//CLEAN UP
	freeIoData(data);
	printf("doneeee\n");
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	printf("doneeee\n");
}