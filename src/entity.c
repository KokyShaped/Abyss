#include "entity.h"


Player createPlayer(IoData* data){
	Vector2 cero = {0,0};

	Player player;
	player.pos = cero;
	player.hp = 10;
	player.solid = true;
	player.spr = createSpriteFromAtlas(cero, data->playerAtlas);
	return player;
}


