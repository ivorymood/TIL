#include <stdio.h>

int main(void)
{
	int n = 0;

	scanf_s("%d", &n);
	
	//1 ~ 9
	if (n < 1)
	{
		n = 1;
	}
	if (n > 9)
	{
		n = 9;
	}


	while (n > 0)
	{
		printf("%c", '*');
		//putchar('*');
		n--;
	}
	printf("\n");

	return 0;
}