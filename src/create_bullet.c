#include "endgame.h"

// создание пули
void create_bullet(obj *bullet, int x, int y, int direction, int type, int level, int *obj_count) {
    create_obj(bullet, x, y, 0, 3, type, level, obj_count);
    bullet -> direction = direction;
    
    //return bullet;
}

