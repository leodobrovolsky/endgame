#include "endgame.h"

// установка здоровья объекта в зависимости от класса и типа (при создании объекта)
int health_choose(int clas, int type, int level) {
    int base_health = 0;
    int level1 = level;

    if (clas == 0)
        base_health = 1000000;

    if (clas == 1){
        if (type == 0)
            base_health = 40;
        if (type == 1)
            base_health = 90;
        if (type == 2)
            base_health = 100;
        if (type == 3)
            base_health = 60;
    }
    if (clas == 2)
        base_health = 500;

    if (clas == 3){
        level1 = 1;
        if (type == 1)
            base_health = 1;
        if (type == 2)
            base_health = 1;
        if (type == 3)
            base_health = 1;
    }
    
    return  base_health * level1;
}

