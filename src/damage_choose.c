#include "endgame.h"

// установка урона объекта (таран) в зависимости от класса и типа (при создании объекта)
int damage_choose(int clas, int type, int level) {
    int base_damage = 0;

    if (clas == 0)
        base_damage = 100;

    if (clas == 1){
        if (type == 0)
            base_damage = 80;
        if (type == 1)
            base_damage = 20;
        if (type == 2)
            base_damage = 50;
        if (type == 3)
            base_damage = 40;
    }
    if (clas == 2)
        base_damage = 100;

    // если класс "пуля", то таран - это способ нанесения ею урона
    if (clas == 3){
        if (type == 1)  // обычный снаряд
            base_damage = 10;
        if (type == 2) // ракета
            base_damage = 50;
        if (type == 3) // лазер
            base_damage = 30;
    }
    
    return  base_damage * level;
}

