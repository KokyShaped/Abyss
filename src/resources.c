#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "resources.h"
#include <stdlib.h>
#include "error.h"
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include "graphics.h"

IoData* initIoData(void){
	IoData* data = malloc(sizeof(IoData));
	data->basePath = getBasePath();
	data->baseResourcePath = getResourcePath(data->basePath);
	return data;
}

void freeIoData(IoData* data){
	SDL_free(data->basePath);
	SDL_free(data->baseResourcePath);
	SDL_free(data);
}


char* getBasePath(void){
	char* value;
	char* basePath = SDL_GetBasePath();

	if (basePath){
		value = basePath;
	} else {
		printf("ERROR WHILE GETTING PATH\n");
		assert(0);
	}
	return value;
}

char* getResourcePath(const char* basePath){

	int lenght = strlen(basePath);

	char* baseResPath = malloc(lenght);
	strcpy(baseResPath, basePath);

// THIS IS SUPAAA WRONGGGGGG
	strcpy(strstr(baseResPath, "src/"), "res/");
	return baseResPath;
	
}

SDL_Texture* loadTexture(const char* path, SDL_Renderer* ren){
	SDL_Texture* texture = NULL;
	
	SDL_Surface* loadedImage = IMG_Load(path);

	if (loadedImage){
		texture = SDL_CreateTextureFromSurface(ren, loadedImage);
		SDL_FreeSurface(loadedImage);

		if (!texture){
			logSDLError("TEX FROM SURFACE");
		}

	} else {
		logSDLError("LOAD IMAGE");
	}
	return texture;
	
}

