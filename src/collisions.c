#include "endgame.h"

void collisions(int obj_num, obj *objects[], int *obj_count) {
    int result = 0;
    ++*obj_count;
    --*obj_count;
    int i = 0;
    int j = 0;
    int x1, x2, y1, y2, rad1, rad2;
    SDL_Rect boom_RECT;
    boom_RECT.x = 0;
    boom_RECT.y = 0;
    boom_RECT.w = 100;
    boom_RECT.h = 100;
    for (i = 0; i < obj_num - 1; i ++) {
        if (objects[i] -> present) {
            x1 = objects[i] -> x;
            y1 = objects[i] -> y;
            rad1 = objects[i] -> radius;

            for (j = i+1; (j < obj_num); j ++) {
                 if (objects[i] -> clas == 2 && objects[j] -> clas == 2) {
                    collision_asteroids(objects[i], objects[j]);
                    continue;
                 }


                if (objects[j] -> present > 0  && objects[i] -> present > 0) {
                    x2 = objects[j] -> x;
                    y2 = objects[j] -> y;
                    rad2 = objects[j] -> radius;
                    result = collision_check(x1, y1, rad1, x2, y2, rad2);
                    if (result) {
                        //collision!
                        //*obj_count -= 1;
                        //check if health = 0
                        objects[i] -> health -= objects[j] -> damage;
                        objects[j] -> health -= objects[i] -> damage;
                        if (objects[i] -> health < 1) {
                            boom_RECT.x = x1 - objects[i] -> rect -> h / 2;
                            boom_RECT.y = y1 - objects[i] -> rect -> w / 2;
                            objects[i] -> present = 0;
                            //*obj_count -= 1;
                        }
                        if ((objects[j] -> health < 1) || i == 0) {
                            boom_RECT.x = x2 - objects[j] -> rect -> h / 2;
                            boom_RECT.y = y2 - objects[j] -> rect -> w / 2;
                            objects[j] -> present = 0;
                            //*obj_count -= 1;
                        }
                        
                    }
                }
            }
        }
    }
}

int collision_check(int x1, int y1, int r1, int x2, int y2, int r2) {
    int result = 0;
    double distance_pow;
    int rad_delta;
    distance_pow = pow((double)abs(x1 - x2), 2) + pow((double)abs(y1 - y2), 2);
    rad_delta = pow((double)(r1 + r2), 2);
    if (rad_delta > distance_pow) 
        result = 1;
    return result;
}

