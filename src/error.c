#include <SDL2/SDL.h>
#include <assert.h>
#include <stdio.h>

void logSDLError(const char* str){
	printf("SDL %s ERROR: %s\n", str, SDL_GetError());
}

void logSDLErrorAndQuit(const char* str){
	logSDLError(str);
	assert(0);// this is temporary...
}