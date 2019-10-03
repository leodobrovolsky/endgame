#include "endgame.h"

// установка скорости объекта в зависимости от класса и типа (при создании объекта)
int speed_choose(int clas, int type) {
    if (clas == 0)
        return 5;
    
    if (clas == 1){
        if (type == 0)
            return 3;
        if (type == 1)
            return 2;
        if (type == 2)
            return 2;
        if (type == 3)
            return 2;
    }        

    if (clas == 2)
        return 2;

    if (clas == 3)
        if (type == 1)
            return 6;
        if (type == 2)
            return 5;
        if (type == 3)
            return 14;
    return 0;

}

