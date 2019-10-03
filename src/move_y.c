#include "endgame.h"

// смещение объекта по Y при движении
int move_y(obj *object) {
    return object -> speed * mx_sin(object -> direction);
}

