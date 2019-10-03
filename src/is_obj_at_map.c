#include "endgame.h"

// проверка на нажатие кнопки выхода
int is_obj_at_map(obj *object) {
    if (object -> x > 10 && object -> x < WINDOW_WIDTH - 10 &&
        object -> y > 10 && object -> y < WINDOW_HEIGHT - 10)
            return 1;
    return 0;
}

