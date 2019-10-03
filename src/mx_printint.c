#include "endgame.h"

void mx_printint(int n) {
	int len = 1;
	int minus = 1;

    if (n < 0) {
		mx_printchar('-');
		minus = -1;
	}
	for (int i = n; i / 10 != 0; i /= 10)
		len *= 10;
	for (int i = len; i > 0; i /= 10) {
		mx_printchar((n / i) * minus + 48);
		n %= i;
	}
}
