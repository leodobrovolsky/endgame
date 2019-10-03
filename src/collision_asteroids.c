#include "endgame.h"
static int check_collision(obj *obj1, obj *obj2) {
    return sqrt(pow(abs(obj1 -> x - obj2 -> x), 2) 
        + pow(abs(obj1 -> y - obj2 -> y), 2)) <= obj1 -> radius + obj2 -> radius;
}

void collision_asteroids(obj *obj1, obj *obj2) {
    int temp = 0;
    if (obj1 -> clas == 2 && obj2 -> clas == 2) {
        if (check_collision(obj1, obj2)) {
            temp = obj1 -> direction;
            obj1 -> direction = obj2 -> direction;
            obj2 -> direction = temp;
        }
    }
}

