#include "endgame.h"

// отрисовывание пули
int get_std_delay(obj *object) {
    int mcsec = 10000;
    if (object -> clas == 0) {
        if (object -> weapon_type == 1)
            return 2 * mcsec;
        if (object -> weapon_type == 2)
            return 3 * mcsec;
        if (object -> weapon_type == 1)
            return 4 * mcsec;
    }

    if (object -> clas == 1) {
        if (object -> weapon_type == 1)
            return 7 * mcsec;
        if (object -> weapon_type == 2)
            return 5 * mcsec;
        if (object -> weapon_type == 3)
            return 15 * mcsec;
    }

    if (object -> clas == 3) {
        if (object -> type == 2)
            return 1 * mcsec;
    }
    return 0;
}

