#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include "definitions.h"


typedef struct {
	SDL_Rect clip;
	SDL_Texture* sourceTex;
}Sprite;

SDL_Rect getPixelRectFromPosition(Vector2 pos);

Sprite* createSpriteFromAtlas(Vector2 pos, SDL_Texture* atlas);

void renderSpriteAt(Vector2 pos, SDL_Renderer* ren, Sprite* spr);

#endif