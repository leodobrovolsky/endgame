#include "endgame.h"

SDL_Surface** mx_skin_bullet(void){
	SDL_Surface** surfaceship = (SDL_Surface**) malloc(sizeof(SDL_Surface*)*3);
        surfaceship[0] = IMG_Load("textures/boolet/bool1.png"); 
          surfaceship[1] = IMG_Load("textures/boolet/bool2.png"); 
          surfaceship[2] = IMG_Load("textures/boolet/bool3.png");  
          for(int i = 0; i < 3; i++)
            if (!surfaceship[i])
        printf("error creating surface boolet%d\n", i);
	 return surfaceship;
} 
