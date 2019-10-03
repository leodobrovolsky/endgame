#include "endgame.h"

// установка радиуса объекта (в пикселах) в зависимости от размера объекта, при его создании
int radius_from_size(obj *object) {

        if (object -> clas == 3)
            return 8;

        if (object -> clas == 0)
            return 45;

        if (object -> clas == 2)
            return 30;

        if (object -> clas == 1){
            if (object -> type == 0)
                return 20;
            if (object -> type == 1)
                return 38;
            if (object -> type == 2)
                return 38;
            if (object -> type == 3)
                return 38;
        }
    
    return 0;
}

