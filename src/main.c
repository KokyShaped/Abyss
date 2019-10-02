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



	printf("%d\n", sizeof(Level));
	//resources and stufff
	IoData* data = initIoData(ren);

	EntityManager entityManager = createEntityManager(data);

	//game loop
	Vector2 randompos = {5,5};
	for (int i = 0; i < 20; i++){
		
		entityManager.player.pos.x = entityManager.player.pos.y = i;
		SDL_RenderClear(ren);

		//renderSpriteAt(randompos, ren, entityManager.level->tileSprites[1]);

		
		
		SDL_RenderPresent(ren);

		SDL_Delay(500);
	}








	//CLEAN UP
	freeIoData(data);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}