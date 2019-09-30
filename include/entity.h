#ifndef ENTITY_H
#define ENTITY_H

#include "definitions.h"
#include <stdbool.h>
#include "stretchy_buffer.h"
#include "graphics.h"
#include "resources.h"

#define MAX_TILES_SIDE 16

typedef enum {
	Empty=0,
	Floor,
	Wall,
	Door,
	Entry,
	Exit,
	tileCount
}TileTypes;



typedef struct{
	bool solid;
	u8 type;
}Tile;


typedef struct{
	Tile tiles[MAX_TILES_SIDE][MAX_TILES_SIDE];
	Sprite** tileSprites;

	//rooms btw
	//to be filled
}Level;

typedef struct{
	Vector2 pos;
	u32 hp;
	bool solid;
	Sprite* sprite;
}Player;

typedef struct{
	Player player;
	Level* level;
}EntityManager;



Player createPlayer(IoData* data);
EntityManager createEntityManager(IoData* data);
Level* createLevel(IoData* data);
void initTiles(Tile* tiles);
#endif