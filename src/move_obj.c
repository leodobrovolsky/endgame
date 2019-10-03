#include "endgame.h"

// перемещение объекта
void move_obj (obj *object) {
    object -> x += move_x(object);
    object -> y += move_y(object);
    xy_obj_rect_sync(object);
}

