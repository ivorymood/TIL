#include <stdio.h>

int main(void)
{
	int i = 0;
	int total = 0;

	while (i <= 10)
	{
		total += ++i;
	}
	
	printf("TOTAL : %d", total);

	return 0;
}