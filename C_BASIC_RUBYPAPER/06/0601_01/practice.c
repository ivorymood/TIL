#include <stdio.h>

int main(void)
{
	int nMax = 0;
	int a = 0;;

	scanf_s("%d", &a);

	nMax = a;

	scanf_s("%d", &a);
	if (a > nMax)
	{
		nMax = a;
	}
	scanf_s("%d", &a);
	if (a > nMax)
	{
		nMax = a;
	}
	
	printf("MAX: %d", nMax);

	return 0;
}