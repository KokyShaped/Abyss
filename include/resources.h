#ifndef RES_H
#define RES_H
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
typedef struct {
	char* basePath;
	char* baseResourcePath;

	char* tileAtlasPath;
	char* playerAtlasPath;

	SDL_Texture* tileAtlas;
	SDL_Texture* playerAtlas;
	
	char* fontPath;
	TTF_Font* font;

}IoData;

typedef struct {
	SDL_Rect clip;
	SDL_Texture* sourceTex;
}Sprite;

char* getBasePath(void);
char* getResourceFolderPath(const char* subDir);

char* getResourceFilePath(const char* baseResourcePath, const char* resource);

void freeIoData(IoData* data);
IoData* initIoData(SDL_Renderer* ren);

SDL_Texture* loadTexture(const char* path, SDL_Renderer* ren);
#endif