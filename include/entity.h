#ifndef ENTITY_H
#define ENTITY_H

#include "definitions.h"
#include <stdbool.h>
#include "stretchy_buffer.h"

typedef struct{
	Player player;
	Level* level;
}EntityManager;

typedef struct{
	Tile* tiles;
	//to be filled
}Level;

typedef struct{
	Vector2 pos;
	u32 hp;
	bool solid;
}Player;



#endif