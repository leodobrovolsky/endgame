#include "endgame.h"

// инициализация структуры текстуры объекта
SDL_Rect * init_rect() {
    SDL_Rect *rect = (SDL_Rect *) malloc (sizeof(SDL_Rect));
    rect -> x = -1;
    rect -> y = -1;
    rect -> w = -1;
    rect -> h = -1;

    return rect;
}

