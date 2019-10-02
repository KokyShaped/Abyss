#include "entity.h"


Player createPlayer(IoData* data){
	Vector2 cero = {0,0};

	Player player;
	player.pos = cero;
	player.hp = 10;
	player.solid = true;
	player.sprite = createSpriteFromAtlas(cero, data->playerAtlas);
	return player;
}


EntityManager createEntityManager(IoData* data){
	EntityManager manager;
	manager.player = createPlayer(data);

	manager.roomcreateRoom

	return manager;
}


Room* createRoom(void){
	Room* room = malloc(sizeof(Room));
	room->height = randInt(3, MAX_TILES_SIDE);
	room->width = randInt(3, MAX_TILES_SIDE);
	room->tiles = NULL;

	sb_add(room->tiles, room->height * room->width);

	int k = 0
	Vector2 pos;
	for(int i = 0; i < room.height; i++){
		for(int j = 0; j < room.width; j++){
			pos.x = i;
			pos.y = j;

			room->tiles[k].pos = pos;
			k++;
		}
	}
}