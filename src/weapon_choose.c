#include "endgame.h"

// выбор оружия объекта в зависимости от класса и типа (при создании объекта)
int weapon_choose(int clas, int type) {
    if (clas == 0)
        return 1;
    
    if (clas == 1)
        return type;

    if (clas == 2 || clas == 3)
        return 0;
    return 0;
}

