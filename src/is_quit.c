#include "endgame.h"

// проверка на нажатие кнопки выхода
int is_quit() {
    SDL_Event event;
    while (SDL_PollEvent(&event))
        if (event.type == SDL_QUIT)
            return 1;
    return 0;
}

