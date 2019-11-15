#include "input.h"


void handleInput(EntityManager* manager, bool* quit){

	SDL_Event e;
	Room* aux;
	while (SDL_PollEvent(&e)){
		
		if (e.type == SDL_QUIT){
			*quit = true;
		}

		if (e.type == SDL_KEYDOWN){
			switch (e.key.keysym.sym)
			{
				case SDLK_ESCAPE:
					*quit = true;
					break;

				case SDLK_1:
					aux = createRoom();
					initRoom(aux);
					addRoom(manager, aux);
					break;

				case SDLK_2:
					advanceRoom(manager);
					break;

				case SDLK_3:
					printf("Number of rooms: %d\n", manager->roomCount);
					break;

				case SDLK_w:
					movePlayer(manager, UP);
					
					break;

				case SDLK_d:
					movePlayer(manager, RIGHT);
					
					break;

				case SDLK_s:
					movePlayer(manager, DOWN);
					
					break;

				case SDLK_a:
					movePlayer(manager, LEFT);
					
					break;

				case SDLK_z:
					if (manager->zoomFactor == 1)
					{
						manager->zoomFactor = 2;
					}
					else if (manager->zoomFactor == 2)
					{
						manager->zoomFactor = 1;
					}
					else
					{
						printf("ERROR ZOOM FACTOR WRONG\n");
						assert(manager->zoomFactor);
					}
					break;

				default:
					printf("not handled key\n");
					break;
			}
		}

		if (e.type == SDL_MOUSEBUTTONDOWN){
			printf("You just pressed a mouse button\n");
		}
	}
}