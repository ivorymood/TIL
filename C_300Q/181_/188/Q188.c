#include <stdio.h>
#include <math.h>

int main(void)
{
	double x = 10.0, y = 3.0, r;

	r = pow(x, y);

	printf("10의 3승은 %g 입니다. \n", r);

	return 0;
}