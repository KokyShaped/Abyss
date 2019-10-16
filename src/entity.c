#include "entity.h"


Player createPlayer(IoData* data){
	Vector2 cero = {1,1};

	Player player;
	player.pos = cero;
	player.hp = 10;
	player.solid = true;
	player.sprite = createSpriteFromAtlas(cero, data->playerAtlas);
	return player;
}



EntityManager* createEntityManager(void){
	EntityManager* manager = malloc(sizeof(EntityManager));
	return manager;
}

void initEntityManager(EntityManager* manager, IoData* data){
	manager->player = createPlayer(data);
	manager->firstRoom = NULL;
	manager->currentRoom = NULL;
	manager->roomCount = 0;
	updateCameraOffset(manager);
	createTileAtlasSprites(data, manager->tileSprites);

}


Room* createRoom(void){
	Room* rtn = malloc(sizeof(Room));
	return rtn;	
}

void initRoom(Room* room){
	room->width = randInt(MIN_SIDE, MAX_SIDE);
	room->height = randInt(MIN_SIDE, MAX_SIDE);
	room->nextRoom = NULL;
	initTiles(room);
}

void initTiles(Room* room){

	for (int i = 0; i < room->width; i++){
		for (int j = 0; j < room->height; j++){
			if (i == 0 || i == room->width-1 ||
				j == 0 || j == room->height-1)
			{
				room->tiles[i][j].type = Wall;
				room->tiles[i][j].solid = true;
			}
			else
			{
				room->tiles[i][j].type = Floor;
				room->tiles[i][j].solid = false;
			}
		}
	}
}

void addRoom(EntityManager* manager, Room* room){
	if (manager->firstRoom == NULL){
		manager->firstRoom = room;
		manager->currentRoom = room;

	}else{
		Room* aux = manager->firstRoom;

		while (aux){
			if (aux->nextRoom == NULL){
				aux->nextRoom = room;
				aux = NULL;

			}else{
				aux = aux->nextRoom;
			}
		}
	}
	manager->roomCount += 1;
}

void advanceRoom(EntityManager* manager){
	if (manager->roomCount == 0){
		printf("tried to advance room when there were none\n");
		assert(0);
	}

	if (manager->currentRoom->nextRoom == NULL){
		manager->currentRoom = manager->firstRoom;
	}

	manager->currentRoom = manager->currentRoom->nextRoom;
}

void updateCameraOffset(EntityManager* manager){
	static Vector2 baseOffset = {SCREEN_WIDTH/TILE_SIZE, SCREEN_HEIGHT/TILE_SIZE};

	manager->cameraOffset.x = manager->player.pos.x + baseOffset.x;
	manager->cameraOffset.y = manager->player.pos.y + baseOffset.y;
}


void movePlayer(EntityManager* manager, MovementType move){	
	static Vector2 moves[4] = {{0,-1},{1,0},{0,1},{-1,0}};
	bool canMove;
	Vector2 pos = addVectors(moves[move], manager->player.pos);

	canMove = !(tileIsSolid(manager->currentRoom, pos));

	if (canMove)
	{
		manager->player.pos = pos;
	}
}

static bool tileIsSolid(Room* room, Vector2 pos){
	if (pos.x < room->width && 0 <= pos.x &&
		pos.y < room->height && 0 <= pos.y)
	{
		return room->tiles[pos.x][pos.y].solid;
	}
	else
	{
		printf("want to go out of bounds\n");
		return true;
	}
}