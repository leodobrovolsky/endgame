#include "endgame.h"

// установка количества очков за уничтожение объекта в зависимости от класса и типа (при создании объекта)
int award_choose(int clas, int type, int level) {
    int type1 = 0;
    if (type == 0)
        type1 = 1;
    else
        type1 = type;

    if (clas == 3) // если это пуля, то за неё 0 очков
    	type1 = 0;

    return clas * type1 * level;
}

