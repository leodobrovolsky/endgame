#include "endgame.h"

// перемещение нашего корабля вверх
void move_hero_up(obj *object) {
    object -> x += move_x(object);
    object -> y += move_y(object);
    xy_obj_rect_sync(object);
}

