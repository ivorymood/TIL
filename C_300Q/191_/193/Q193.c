#include <stdio.h>

#define max(x,y) (x > y ? x : y)
#define min(x,y) (x < y ? x : y)

int main(void)
{
	printf("최대값 : %d\n", max(5, 3));
	printf("최소값 : %d\n", min(5, 3));
	printf("최대값 : %g\n", max(3.5, 4.4));
	printf("최소값 : %g\n", min(3.5, 4.4));

	return 0;
}