#include "endgame.h"

void set_direction_rocket(obj *p_obj, obj *p_me) {
    if (p_obj -> clas == 3 && p_obj -> type == 2) {
        if (get_obj_delay(p_obj) < 1000)
            return;
        if (get_obj_delay(p_obj) >= 1000 && get_obj_delay(p_obj) < 2000) {
            double x = p_me -> x - p_obj -> x;
            double y = p_me -> y - p_obj -> y;
            int sign = 1;
            if (x == 0)
                x++;
           
            double dir_of_enemy = 90 - (atan(fabs(x) / fabs(y)) * (180 / 3.1415));
            if (x > 0 && y < 0)
                dir_of_enemy += 270;
            if (x < 0 && y > 0)
                dir_of_enemy += 90;
            if (x < 0 && y < 0)
                dir_of_enemy += 180;

 
            if (fabs(dir_of_enemy - p_obj -> direction) > 180)
                sign = -1;
            if (fabs(dir_of_enemy - p_obj -> direction) > p_obj -> rotate_speed)
                    p_obj -> direction += (p_obj -> rotate_speed * sign); 

            else 
                 p_obj -> direction = (int) dir_of_enemy;
                }
        if (get_obj_delay(p_obj) >= 2000) {
            set_obj_timer(p_obj);
        }
    }
      
}
