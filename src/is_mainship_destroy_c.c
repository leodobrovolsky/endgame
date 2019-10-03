#include "endgame.h"

int is_mainship_destroy(obj *mainship) {
    if (mainship -> present)
    	return 0;
    else
    	return 1;
}

