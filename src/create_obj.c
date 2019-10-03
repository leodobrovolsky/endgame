#include "endgame.h"

// создание объекта
void create_obj(obj *object, int x, int y, int size, int clas, int type, int level, int *obj_count) /* 6 параметров*/ {

    //obj *object = (obj)malloc(sizeof(obj));

    object -> x = x;
    object -> y = y;
    object -> direction = 0;

    object -> size = size;
    object -> clas = clas;
    object -> type = type;
    object -> level = level;

    object -> max_speed = speed_choose(clas, type);
    object -> speed = object -> max_speed;
    object -> rotate_speed = rotate_speed_choose(clas, type);
    object -> health = health_choose(clas, type, level);
    object -> weapon_type = weapon_choose(clas, type);
    object -> damage = damage_choose(clas, type, level);
    object -> award = award_choose(clas, type, level);

    object -> present = 1;
    object -> obj_timer = 10;
    
    int w = w_from_size(object);
    int h = h_from_size(object);

    object -> radius = radius_from_size(object);
    object -> review = review_from_radius(object -> radius);

    create_rect(object -> rect, x - w / 2, y - h / 2, w, h);


    //mx_printint(*obj_count);

    (*obj_count)++;

    //mx_printint(*obj_count);
    //mx_printchar('\n');

    //xy_obj_rect_sync(object);

    //return object;
}

