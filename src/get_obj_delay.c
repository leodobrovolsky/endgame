#include "endgame.h"

int get_obj_delay(obj *object) {
    return (int) (clock() - object -> obj_timer);
}

