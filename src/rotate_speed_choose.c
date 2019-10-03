#include "endgame.h"

// установка угловой скорости объекта (градусы в такт) в зависимости от класса и типа (при создании объекта)
int rotate_speed_choose(int clas, int type) {
    int type_speed = 0;
    if (clas == 2 || clas == 3){ //если астероид или снаряд
        if (type == 2) // Если снаряд: ракета
            return 1;
        return 0;
    }

    if (clas == 0)
        type_speed = 3;

    return  2;
}

