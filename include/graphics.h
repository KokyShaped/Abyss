#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include "definitions.h"
#include "entity.h"


typedef struct {
	SDL_Rect clip;
	SDL_Texture* sourceTex;
}Sprite;
//a sprite is a clip rect of the image at the position in pixels of the atlas
//and a pointer to the atlas

SDL_Rect getPixelRectFromPosition(Vector2 pos);

Sprite* createSpriteFromAtlas(Vector2 pos, SDL_Texture* atlas);

void renderSpriteAt(Vector2 pos, SDL_Renderer* ren, Sprite* spr);

void renderTiles(Level* level, SDL_Renderer* ren);

#endif