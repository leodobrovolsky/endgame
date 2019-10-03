#include "endgame.h"

// синхронизация положения центра объекта и верхнего левого угла текстуры
void xy_obj_rect_sync (obj *object) {
    object -> rect -> x = object -> x - object -> rect -> w / 2;
    object -> rect -> y = object -> y - object -> rect -> h / 2;
}

