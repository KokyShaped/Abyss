#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "resources.h"
#include <stdlib.h>
#include "error.h"
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include "graphics.h"
#include "entity.h"
#include "error.h"


IoData* initIoData(SDL_Renderer* ren){
	IoData* data = malloc(sizeof(IoData));

	data->basePath = getBasePath();
	data->baseResourcePath = getResourceFolderPath(data->basePath);

	data->tileAtlasPath = getResourceFilePath(data->baseResourcePath, "Floor.png");
	data->playerAtlasPath = getResourceFilePath(data->baseResourcePath, "Player.png");

	data->tileAtlas = loadTexture(data->tileAtlasPath, ren);
	data->playerAtlas = loadTexture(data->playerAtlasPath, ren);


	data->fontPath = getResourceFilePath(data->baseResourcePath, "sample.ttf");
	data->font = TTF_OpenFont(data->fontPath, 16);

	if (!(data->font)){
		logSDLError("FONT");
	}

	return data;
}

void freeIoData(IoData* data){
	SDL_free(data->basePath);
	SDL_free(data->baseResourcePath);

	SDL_free(data->playerAtlasPath);
	SDL_free(data->tileAtlasPath);

	SDL_DestroyTexture(data->playerAtlas);
	SDL_DestroyTexture(data->tileAtlas);

	SDL_free(data->fontPath);
	TTF_CloseFont(data->font);

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

char* getResourceFolderPath(const char* basePath){

	int lenght = strlen(basePath);

	char* baseResPath = malloc(lenght);
	strcpy(baseResPath, basePath);

// THIS IS SUPAAA WRONGGGGGG
	strcpy(strstr(baseResPath, "src/"), "res/");
	return baseResPath;
	
}

char* getResourceFilePath(const char* baseResourcePath, const char* resource){
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
