#include "endgame.h"

SDL_Surface** mx_skin_asteroid(void){
	SDL_Surface** surfaceship = (SDL_Surface**) malloc(sizeof(SDL_Surface*)*7);
          surfaceship[0] = IMG_Load("textures/asteroids/astr1.png"); 
          surfaceship[1] = IMG_Load("textures/asteroids/astr2.png"); 
          surfaceship[2] = IMG_Load("textures/asteroids/astr3.png"); 
          surfaceship[3] = IMG_Load("textures/asteroids/astr4.png"); 
          surfaceship[4] = IMG_Load("textures/asteroids/astr5.png"); 
          surfaceship[5] = IMG_Load("textures/asteroids/astr6.png"); 
          surfaceship[6] = IMG_Load("textures/asteroids/astr7.png"); 
          surfaceship[7] = IMG_Load("textures/asteroids/astr8.png"); 
          surfaceship[8] = IMG_Load("textures/asteroids/astr9.png"); 
          for(int i = 0; i < 9; i++)
            if (!surfaceship[i])
        printf("error creating surface asteroid%d\n", i);
	 return surfaceship;
} 
