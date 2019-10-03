#include "endgame.h"

// создание астероида
void create_asteroid(obj *asteroid, int x, int y, int direction, int size, int level, int *obj_count) {
    create_obj(asteroid, x, y, size, 2, 0, level, obj_count);
    asteroid -> direction = direction;

    //return asteroid;
}

