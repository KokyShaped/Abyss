#ifndef ENTITY_H
#define ENTITY_H

#include "definitions.h"
#include <stdbool.h>
#include "stretchy_buffer.h"
#include "graphics.h"
#include "resources.h"


typedef enum {
	Empty=0,
	Floor,
	Wall,
	Door,
	Entry,
	Exit,
	count
}TileTypes;



typedef struct{
	bool solid;
	u8 type;
}Tile;


typedef struct{
	Tile* tiles;
	Sprite* tileSprites;
	//to be filled
}Level;

typedef struct{
	Vector2 pos;
	u32 hp;
	bool solid;
	Sprite* spr;
}Player;

typedef struct{
	Player player;
	Level* level;
}EntityManager;



Player createPlayer(IoData* data);

#endif