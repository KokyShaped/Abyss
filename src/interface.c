#include "stretchy_buffer.h"
#include "interface.h"




TextLabel* createTextLabel(EntityManager* manager, SDL_Renderer* ren, const char* string){
	TextLabel* label = malloc(sizeof(TextLabel));

	label->string = malloc(strlen(string)+1);
	strcpy(label->string, string);

	label->tex = stringToTexture(manager, ren, label->string);
	return label;
}

LabelColumn* createLabelColumn(SDL_Rect* region){
	LabelColumn* column = malloc(sizeof(LabelColumn));

	assert(region);
	column->region = *region;
	column->labels = NULL;
	return column;
}

void pushTextLabel(LabelColumn* column, TextLabel* label){
	sb_push(column->labels, label);
}



void destroyTextLabel(TextLabel* label){
	SDL_free(label->string);
	SDL_DestroyTexture(label->tex);
	SDL_free(label);
}


void destroyTextColumn(LabelColumn* column){
	for (int i = 0; i < sb_count(column->labels); i++){
		destroyTextLabel(column->labels[i]);
	}

	sb_free(column->labels);
	SDL_free(column);
}


void initUI(EntityManager* manager, SDL_Renderer* ren){

	SDL_Rect topLeft  = {0, 0, 100, 100};
	manager->column = createLabelColumn(&topLeft);

	char* string = malloc(sizeof(char*)*256);
	sprintf(string, "The number of rooms is %d", manager->roomCount);

	TextLabel* aux;
	aux = createTextLabel(manager, ren, string);
	pushTextLabel(manager->column, aux);


	sprintf(string, "")
}

void updateUI(EntityManager* manager, SDL_Renderer* ren){
	for (int i = 0; i < sb_count(manager->column); i++){

		SDL_DestroyTexture(manager->labels[i].tex);
	}


}



//simple version that breaks the limits of the region but whatever
void renderLabelColumn(SDL_Renderer* ren, LabelColumn* column){
	if (column->labels){
		Vector2 pos;
		pos.x = column->region.x;
		pos.y = column->region.y;

		TextLabel* label = column->labels[0];
		for (int i = 0; i < sb_count(column->labels); i++){
			renderTextureAt(label->tex, ren, pos);
			
			if (i+1 < sb_count(column->labels)){
				pos.y += TEXT_SIZE;
				label = column->labels[i+1];
			}
		}
	}
}