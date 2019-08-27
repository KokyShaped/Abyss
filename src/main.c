#include <stddef.h>
#include "definitions.h"
#include <assert.h>
#include <stdio.h>
#include "random.h"
#include "resources.h"
#include <SDL2/SDL.h>
#include "error.h"





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
	IoData* data = initIoData();
	printf("The path is: %s\n", data->basePath);
	printf("The path is: %s\n", data->baseResourcePath);


	char* imagePath = malloc(strlen(data->baseResourcePath) + 30);
	strcpy(imagePath, data->baseResourcePath);
	strcat(imagePath, "Player0.png");
	printf("%s\n", imagePath);

	SDL_Texture* tex = loadTexture(imagePath, ren);
	if (tex == NULL){
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return 1;
	}

	for (int i = 0; i < 3; i++){
		SDL_RenderClear(ren);

		SDL_RenderCopy(ren, tex, NULL, NULL);

		SDL_RenderPresent(ren);

		SDL_Delay(1000);
	}








	//CLEAN UP
	freeIoData(data);
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}