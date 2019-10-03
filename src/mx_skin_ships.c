#include "endgame.h"

SDL_Surface** mx_skin_ships(void){
	SDL_Surface** surfaceship = (SDL_Surface**) malloc(sizeof(SDL_Surface*)*7);
          surfaceship[0] = IMG_Load("textures/spaceships/ship1.png"); 
          surfaceship[1] = IMG_Load("textures/spaceships/ship2.png"); 
          surfaceship[2] = IMG_Load("textures/spaceships/ship3.png"); 
          surfaceship[3] = IMG_Load("textures/spaceships/ship4.png"); 
          surfaceship[4] = IMG_Load("textures/spaceships/ship5.png"); 
          surfaceship[5] = IMG_Load("textures/spaceships/ship6.png"); 
          surfaceship[6] = IMG_Load("textures/spaceships/ship7.png"); 
          for(int i = 0; i < 7; i++)
       if (!surfaceship[i])
   printf("error creating surface spaceships%d\n", i);
	 return surfaceship;
} 
