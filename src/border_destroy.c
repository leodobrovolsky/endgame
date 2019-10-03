#include "endgame.h"

void border_destroy(obj *object) {
	int x_size = WINDOW_WIDTH;
	int y_size = WINDOW_HEIGHT;
    if (object -> clas == 2 || object -> clas == 3 || object -> clas == 1) {
    	if (object -> x <= -200 || object -> y <= -200 || object -> x >= x_size + 200 || object -> y >= y_size + 200) {
    		object -> present = 0;
    	}
    }
}
