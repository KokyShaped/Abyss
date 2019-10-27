#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include "definitions.h"
#include "resources.h"
#include "entity.h"
#include <assert.h>


//a sprite is a clip rect of the image at the position in pixels of the atlas
//and a pointer to the atlas

SDL_Rect getPixelRectFromPosition(Vector2 pos);

Sprite* createSpriteFromAtlas(Vector2 pos, SDL_Texture* atlas);

void renderSpriteAt(EntityManager* manager, Vector2 pos, SDL_Renderer* ren, Sprite* spr);

void drawCurrentRoom(EntityManager* manager, SDL_Renderer* ren);

void createTileAtlasSprites(IoData* data, Sprite** sprites);

void drawPlayer(EntityManager* manager, SDL_Renderer* ren);

#endif