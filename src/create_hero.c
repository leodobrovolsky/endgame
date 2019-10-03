#include "endgame.h"

// создание нашего корабля
void create_hero(obj *object, int x, int y, int level, int *obj_count) {
    create_obj(object, x, y, 3, 0, 0, level, obj_count);
}

