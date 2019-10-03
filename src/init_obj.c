#include "endgame.h"

// инициализация объекта
obj *init_obj() {

    obj *object = (obj*)malloc(sizeof(obj));

    object -> x = -1;
    object -> y = -1;
    object -> direction = -1;

    object -> size = -1;
    object -> clas = -1;
    object -> type = -1;
    object -> level = -1;

    object -> max_speed = -1;
    object -> speed = -1;
    object -> rotate_speed = -1;
    object -> health = -1;
    object -> weapon_type = -1;
    object -> damage = -1;
    object -> award = -1;

    object -> present = 0;
    object -> obj_timer = 0;

    object -> radius = -1;
    object -> review = -1;

    object -> rect = init_rect();

    //xy_obj_rect_sync(object);

    return object;
}

