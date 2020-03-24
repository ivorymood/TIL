#include <stdio.h>

#define COUNT 100

#if !defined COUNT
#define COUNT 90
#endif

int main(void)
{
	printf("COUNT : %d \n", COUNT);
	return 0;
}