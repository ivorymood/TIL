#include <stdio.h>

int main(void)
{
	int wage = 1000;
	int age = 0;
	int discount = 0;

	scanf_s("%d", &age);

	if (age < 20)
	{
		discount = 25;
	}

	printf("%d", wage * (100 - discount) / 100);

	return 0;
}