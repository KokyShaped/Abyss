#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "resources.h"
#include <stdlib.h>
#include "error.h"
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include "graphics.h"

IoData* initIoData(SDL_Renderer* ren){
	IoData* data = malloc(sizeof(IoData));

	data->basePath = getBasePath();
	data->baseResourcePath = getResourcePath(data->basePath);

	data->tileAtlasPath = getAtlasPath(data->baseResourcePath, "Floor.png");
	data->playerAtlasPath = getAtlasPath(data->baseResourcePath, "Player.png");

	data->tileAtlas = loadTexture(data->tileAtlasPath, ren);
	data->playerAtlas = loadTexture(data->playerAtlasPath, ren);

	return data;
}

void freeIoData(IoData* data){
	SDL_free(data->basePath);
	SDL_free(data->baseResourcePath);

	SDL_free(data->playerAtlasPath);
	SDL_free(data->tileAtlasPath);

	SDL_DestroyTexture(data->playerAtlas);
	SDL_DestroyTexture(data->tileAtlas);

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

char* getAtlasPath(const char* baseResourcePath, const char* resource){
	int lenght = strlen(baseResourcePath) + strlen(resource);
	
	char* atlasPath = malloc(lenght);

	strcpy(atlasPath, baseResourcePath);
	strcat(atlasPath, resource);
	printf("The Atlas path is: %s\n", atlasPath);
	return atlasPath;
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


