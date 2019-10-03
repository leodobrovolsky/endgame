#include "endgame.h"

// смещение объекта по Х при движении
int move_x(obj *object) {
    return object -> speed * mx_cos(object -> direction);
}

