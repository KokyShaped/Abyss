#ifndef INTERFACE_H
#define INTERFACE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <string.h>




typedef struct{
	char* string;
	SDL_Texture* tex;
}TextLabel;

typedef struct LabelColumn{
	SDL_Rect region;
	TextLabel** labels;
}LabelColumn;



#include "entity.h"
#include "graphics.h"
TextLabel* createTextLabel(EntityManager* manager, SDL_Renderer* ren, const char* string);

LabelColumn* createLabelColumn(SDL_Rect* region);

void destroyTextLabel(TextLabel* label);

void pushTextLabel(LabelColumn* column, TextLabel* label);



void initUI(EntityManager* manager, SDL_Renderer* ren);

//simple version that breaks the limits of the region but whatever
void renderLabelColumn(SDL_Renderer* ren, LabelColumn* column);

void updateUI(EntityManager* manager, SDL_Renderer* ren);
#endif