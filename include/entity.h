#ifndef ENTITY_H
#define ENTITY_H

#include "definitions.h"
#include <stdbool.h>
#include "stretchy_buffer.h"
#include "resources.h"
#include "random.h"

#define MIN_SIDE 4
#define MAX_SIDE 16

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

typedef struct Room{
	Tile tiles[MAX_SIDE][MAX_SIDE];

	u8 width;
	u8 height;

	struct Room* nextRoom;
}Room;


typedef struct{
	Vector2 pos;
	u32 hp;
	bool solid;
	Sprite* sprite;
}Player;



typedef struct{
	Player player;

	Sprite* tileSprites[tileCount];

	Room* firstRoom;
	Room* currentRoom;
	u32 roomCount;

}EntityManager;

#include "graphics.h"

Player createPlayer(IoData* data);

EntityManager* createEntityManager(void);

void initEntityManager(EntityManager* manager, IoData* data);

Room* createRoom(void);

void initRoom(Room* room);

void initTiles(Room* room);

void addRoom(EntityManager* manager, Room* room);

void advanceRoom(EntityManager* manager);
#endif