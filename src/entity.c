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

	manager.level = createLevel(data);
	initTiles(manager.level->tiles)
	return manager;
}

Level* createLevel(IoData* data){
	Level* level = malloc(sizeof(Level));

	TileTypes count = tileCount;

	sb_add(level->tileSprites, count);
	printf("%d\n", sb_count(level->tileSprites));
	Vector2 current = {5,0};
	level->tileSprites[0] = createSpriteFromAtlas(current, data->tileAtlas);

	current.x = 5;
	current.y = 3;
	level->tileSprites[1] = createSpriteFromAtlas(current, data->tileAtlas);
	return level;
}

void initTiles(Tile* tiles){
	for (int i = 0; i < MAX_TILES_SIDE; i++){
		for (int j = 0; j < MAX_TILES_SIDE; j++){

			if (i == 0; || i == 10){
				tile[i][j].solid = true;
				tile[i][j].type = Floor;
			}else{
				tile[i][j].solid = false;
				tile[i][j].type = Empty;
			}
		}
	}
}