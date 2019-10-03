#include "endgame.h"

void array_zip(obj *objects[], int *obj_count) {
    int i;
    obj *tmp_obj;
    for (i = 1; i < *obj_count; i ++) {
        if (objects[i] -> present == 0) {
        	tmp_obj = objects[i];
        	objects[i] = objects[*obj_count - 1];
        	objects[*obj_count - 1] = tmp_obj;
        	*obj_count -= 1;
        	//i -=1;   	
        }
    }
}

