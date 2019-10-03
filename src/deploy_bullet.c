#include "endgame.h"

// отрисовывание пули
void deploy_bullet(obj *object, obj *bullet, int *obj_count) {
    int x = object -> x + (object -> radius + 5 + 3) * mx_cos(object -> direction);
    int y = object -> y + (object -> radius + 5 + 3) * mx_sin(object -> direction);
	//x, y clculate from enemy

    int level;
    if (object -> clas == 0)
        level = object -> level + 3;
    else
        level = object -> level;
    //*obj_count += 2;
    create_bullet(bullet, x, y, object -> direction, object -> weapon_type, level, obj_count);
}

