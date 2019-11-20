#ifndef INTERFACE_H
#define INTERFACE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <string.h>
#include "stretchy_buffer.h"


typedef struct{
	char* string;
	SDL_Texture* tex;
}TextLabel;

typedef struct{
	SDL_Rect region;
	TextLabel* labels;
}LabelColumn;



#endif