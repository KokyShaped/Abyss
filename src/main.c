
#include <assert.h>
#include <stdio.h>
#include "random.h"
#include "resources.h"
#include <SDL2/SDL.h>



int main(){
	IoData* data = initIoData();

	printf("The path is: %s\n", data->basePath);
	printf("The path is: %s\n", data->baseResourcePath);
	freeIoData(data);
}