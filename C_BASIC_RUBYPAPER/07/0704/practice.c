#include <stdio.h>

int main(void)
{
	int i = 1;
	int num = 0;

	printf("2~9 ют╥б : ");
	scanf_s("%d", &num);

	if (num < 2 || num > 9)
	{
		printf("ERROR");
		return 0;
	}

	while (i < 10)
	{
		printf("%d * %d = %d\n", num, i, num * i);
		i++;
	}

	return 0;
}