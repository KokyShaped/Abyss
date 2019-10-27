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

void renderSpriteAt(EntityManager* manager, Vector2 pos, SDL_Renderer* ren, Sprite* spr){
	Vector2 position = addVectors(pos, manager->cameraOffset);

	SDL_Rect destRect = getPixelRectFromPosition(position);

	SDL_RenderCopy(ren, spr->sourceTex, &(spr->clip), &destRect);
}

void drawCurrentRoom(EntityManager* manager, SDL_Renderer* ren){
	TileTypes type;
	Room* room = manager->currentRoom;
	Vector2 pos = {0,0};

	for (int i = 0; i < manager->currentRoom->width; i++){
		for (int j = 0; j < manager->currentRoom->height; j++){
			type = (room->tiles[i][j]).type;
			assert(type < tileCount);
			pos.x = i;
			pos.y = j;
			renderSpriteAt(manager, pos, ren, manager->tileSprites[type]);
		}
	}
}


void drawPlayer(EntityManager* manager, SDL_Renderer* ren){
	renderSpriteAt(manager, manager->player.pos, ren, manager->player.sprite);
}


void createTileAtlasSprites(IoData* data, Sprite** sprites){
	Vector2 pos = {0,0};
	pos.x = 5;
	pos.y = 0;
	sprites[Empty] = createSpriteFromAtlas(pos, data->tileAtlas);

	pos.x = 8;
	pos.y = 19;
	sprites[Floor] = createSpriteFromAtlas(pos, data->tileAtlas);

	pos.x = 5;
	pos.y = 9;
	sprites[Wall] = createSpriteFromAtlas(pos, data->tileAtlas);

	pos.x = 19;
	pos.y = 18;
	sprites[Entry] = createSpriteFromAtlas(pos, data->tileAtlas);

	pos.x = 19;
	pos.y = 21;
	sprites[Exit] = createSpriteFromAtlas(pos, data->tileAtlas); 
}

