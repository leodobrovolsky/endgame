#include "endgame.h"

// установка высоты текстуры (в пикселах) в зависимости от размера объекта, при его создании
int h_from_size(obj *object) {


        if (object -> clas == 0)
            return 75;
     
        if (object -> clas == 1){
            if (object -> type == 0)
                return 60;
            if (object -> type == 1)
                return 90;
            if (object -> type == 2)
                return 90;
            if (object -> type == 3)
                return 90;
        }

        if (object -> clas == 2)
            return 100;

        if (object -> clas == 3)
            return 12;
    return 0;
}

