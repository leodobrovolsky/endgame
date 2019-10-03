#include "endgame.h"

// ограничение движения корабля по периметру окна
void border_of_move(obj *mainship) {
    if(mainship -> x < 50)
        mainship -> x = 50;
    if(mainship -> x > WINDOW_WIDTH - 50)
        mainship -> x =  WINDOW_WIDTH - 50;
    if(mainship -> y < 50)
        mainship -> y = 50;
    if(mainship -> y > WINDOW_HEIGHT - 50)
        mainship -> y =  WINDOW_HEIGHT - 50;
    xy_obj_rect_sync (mainship);
}

