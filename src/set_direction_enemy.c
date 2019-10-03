#include "endgame.h"

void set_direction_enemy(obj *p_obj, obj *p_me) {
    /*if (counter < 0)
        return;*/
    double x = p_me -> x - p_obj -> x;
    double y = p_me -> y - p_obj -> y;
    int sign = 1;
    if (y == 0)
        y++;

    double dir_of_enemy = 90 - (atan(fabs(x) / fabs(y)) * (180 / 3.1415));
    if (x > 0 && y < 0)
        dir_of_enemy += 270;
    if (x < 0 && y > 0)
        dir_of_enemy += 90;
    if (x < 0 && y < 0)
        dir_of_enemy += 180;


    if (dir_of_enemy == 180)
        dir_of_enemy ++;

    if (fabs(dir_of_enemy - p_obj -> direction) > 180)
        sign = 1;
        
    if (fabs(dir_of_enemy - p_obj -> direction) > p_obj -> rotate_speed)
            p_obj -> direction += (p_obj -> rotate_speed * sign); 

    else 
         p_obj -> direction = (int) dir_of_enemy;


            if(p_obj -> direction >= 360)
                p_obj -> direction %= 360;
            if(p_obj -> direction < 0)
                p_obj -> direction =  360 - p_obj -> direction;

}
