#include "endgame.h"

SDL_Surface** mx_skin_bkground(void){
	SDL_Surface** surfacebg = (SDL_Surface**) malloc(sizeof(SDL_Surface*)*4);
      surfacebg[0] = IMG_Load("textures/backgrounds/space1.jpg"); 
      surfacebg[1] = IMG_Load("textures/backgrounds/space2.jpg"); 
      surfacebg[2] = IMG_Load("textures/backgrounds/space3.jpg"); 
      surfacebg[3] = IMG_Load("textures/backgrounds/space4.jpg"); 
          for(int i = 0; i < 4; i++)
            if (!surfacebg[i])
        printf("error creating surface backgrounds%d\n", i);
	 return surfacebg;
} 
