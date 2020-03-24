#include <stdio.h>

#define x_i(x, i) printf("x%s의 값은 %d입니다. \n", #i, x##i);
#define px_i(x, i) printf("_x%c의 값은 %d입니다. \n", #@i, x##i);

int main(void)
{
	int xa = 3;
	int xb = 5;

	x_i(x, a);
	x_i(x, b);

	px_i(x, a);
	px_i(x, b);
	return 0;
}