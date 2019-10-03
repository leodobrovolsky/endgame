#include "endgame.h"

// установка ширины текстуры (в пикселах) в зависимости от размера объекта, при его создании
int w_from_size(obj *object) {
        

        if (object -> clas == 0)
            return 105;
     
        if (object -> clas == 1){
            if (object -> type == 0)
                return 100;
            if (object -> type == 1)
                return 150;
            if (object -> type == 2)
                return 150;
            if (object -> type == 3)
                return 150;
        }

        if (object -> clas == 2)
            return 100;

        if (object -> clas == 3){
            if (object -> type == 3)
                return 90;
            else
                return 40;
        }

    return 0;
}

