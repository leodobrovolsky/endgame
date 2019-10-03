#include "endgame.h"

void obj_overwrite(obj *object[], int obj_num, int *obj_count, double enemy_time) {
	int x_size = WINDOW_WIDTH;
	int y_size = WINDOW_HEIGHT;
	int enemy_num = 0;
	int asteroids_num = 0;
	int create_param = rand() % 2 +1;

	int kvadr = rand() % 4 + 1 ;

	int x = rand() % 2;
	int y = rand() % 2;
	int size = 2;
	int type = rand() % 4;
	if (type == 2)
		type = 0;
    int level = 1;
    int direction = 0;

    if (*obj_count < obj_num) {
        for (int i = 1; i < *obj_count; i++) {
         	if (object[i] -> clas == 1 && object[i] -> present >0 )
         		enemy_num++;
         	if (object[i] -> clas == 2 && object[i] -> present >0 )
         		asteroids_num++;
        }

        if (enemy_num <= (int) (clock() - enemy_time)/CLOCKS_PER_SEC* 2 && create_param == 1) {
			if (kvadr == 1){
				x = rand() % x_size;
				y = -50;
			}
			if (kvadr == 2){
				x = x_size + 50;
				y = rand() % y_size;
			}
			if (kvadr == 3){
				x = rand() % x_size;
				y = y_size+50;
			}
			if (kvadr == 4){
				x = -50;
				y = rand() % y_size;
			}
         	create_enemy(object[*obj_count], x, y, size, type, level, obj_count);
         }

         if (asteroids_num <= 15 && create_param == 2) {
			if (kvadr == 1){
				x = rand() % x_size;
				y = -50;
				direction = rand() % 100 + 40;
			}
			if (kvadr == 2){
				x = x_size + 50;
				y = rand() % y_size;
				direction = rand() % 100 + 130;
			}
			if (kvadr == 3){
				x = rand() % x_size;
				y = y_size+50;
				direction = rand() % 100 + 220;
			}
			if (kvadr == 4){
				x = -50;
				y = rand() % y_size;
				direction = rand() % 100 - 40;
			}
         	create_asteroid(object[*obj_count], x, y, direction, size, level, obj_count);
         }
     }
}
