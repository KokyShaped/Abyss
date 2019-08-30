#include "graphics.h"

static u32 zoomFactor = 1;


SDL_Rect getPixelRectFromPosition(Vector2 pos){
	SDL_Rect rect;
	rect.x = pos.x*TILE_SIZE*zoomFactor;
	rect.y = pos.y*TILE_SIZE*zoomFactor;
	rect.h = rect.w = TILE_SIZE*zoomFactor;
	return rect;
}

Sprite* createSpriteFromAtlas(Vector2 pos, SDL_Texture* atlas){
	Sprite *spr = malloc(sizeof(Sprite));

	spr->clip.x = pos.x*ATLAS_RES;
	spr->clip.y = pos.y*ATLAS_RES;
	spr->clip.h = spr->clip.w = ATLAS_RES;

	spr->sourceTex = atlas;
	return spr;
}

void renderSpriteAt(Vector2 pos, SDL_Renderer* ren, Sprite* spr){

	SDL_Rect destRect = getPixelRectFromPosition(pos);

	SDL_RenderCopy(ren, spr->sourceTex, &(spr->clip), &destRect);
}
