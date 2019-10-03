#include "endgame.h"

// создание врагов
void create_enemy(obj *object, int x, int y, int size, int type, int level, int *obj_count) {
    create_obj(object, x, y, size, 1, type, level, obj_count);
}

