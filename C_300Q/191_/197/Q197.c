#include <stdio.h>

#define COUNT 100

#if COUNT != 100
#error "COUNT != 100"
#endif

int main(void)
{
	printf("COUNT : %d \n", COUNT);

	return 0;
}