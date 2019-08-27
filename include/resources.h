#ifndef RES_H
#define RES_H
#include <SDL2/SDL_image.h>
typedef struct {
	char* basePath;
	char* baseResourcePath;

}IoData;

char* getBasePath(void);
char* getResourcePath(const char* subDir);


void freeIoData(IoData* data);
IoData* initIoData(void);

SDL_Texture* loadTexture(const char* path, SDL_Renderer* ren);
#endif