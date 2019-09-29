#ifndef RES_H
#define RES_H
#include <SDL2/SDL_image.h>
typedef struct {
	char* basePath;
	char* baseResourcePath;

	char* tileAtlasPath;
	char* playerAtlasPath;

	SDL_Texture* tileAtlas;
	SDL_Texture* playerAtlas;

}IoData;

char* getBasePath(void);
char* getResourcePath(const char* subDir);

char* getAtlasPath(const char* baseResourcePath, const char* resource);

void freeIoData(IoData* data);
IoData* initIoData(SDL_Renderer* ren);

SDL_Texture* loadTexture(const char* path, SDL_Renderer* ren);
#endif