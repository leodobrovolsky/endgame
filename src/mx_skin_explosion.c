#include "endgame.h"

SDL_Surface** mx_skin_explosion(void){
   SDL_Surface** explosion = (SDL_Surface**) malloc(sizeof(SDL_Surface*)*24);
   explosion[0] = IMG_Load("textures/explosion/exp1.png");
   explosion[1] = IMG_Load("textures/explosion/exp2.png");
   explosion[2] = IMG_Load("textures/explosion/exp3.png");
   explosion[3] = IMG_Load("textures/explosion/exp4.png");
   explosion[4] = IMG_Load("textures/explosion/exp5.png");
   explosion[5] = IMG_Load("textures/explosion/exp6.png");
   explosion[6] = IMG_Load("textures/explosion/exp7.png");
   explosion[7] = IMG_Load("textures/explosion/exp8.png");
   explosion[8] = IMG_Load("textures/explosion/exp9.png");
   explosion[9] = IMG_Load("textures/explosion/exp10.png");
   explosion[10] = IMG_Load("textures/explosion/exp11.png");
   explosion[11] = IMG_Load("textures/explosion/exp12.png");
   explosion[12] = IMG_Load("textures/explosion/exp13.png");
   explosion[13] = IMG_Load("textures/explosion/exp14.png");
   explosion[14] = IMG_Load("textures/explosion/exp15.png");
   explosion[15] = IMG_Load("textures/explosion/exp16.png");
   explosion[16] = IMG_Load("textures/explosion/exp17.png");
   explosion[17] = IMG_Load("textures/explosion/exp18.png");
   explosion[18] = IMG_Load("textures/explosion/exp19.png");
   explosion[19] = IMG_Load("textures/explosion/exp20.png");
   explosion[20] = IMG_Load("textures/explosion/exp21.png");
   explosion[21] = IMG_Load("textures/explosion/exp22.png");
   explosion[22] = IMG_Load("textures/explosion/exp23.png");
   explosion[23] = IMG_Load("textures/explosion/exp24.png");
   for(int i = 0; i < 24; i++)
       if (!explosion[i])
   printf("error creating surface explosion%d\n", i);
   return explosion;
}
