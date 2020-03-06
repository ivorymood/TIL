#include <stdio.h>

int main(void)
{
	int age = 0;
	int wage = 1000;
	int discount = 0;

	printf("나이 입력 : ");
	scanf_s("%d", &age);

	if (age < 4)
	{
		discount = 100;
	}
	else if (age < 14)
	{
		discount = 50;
	}
	else if (age < 20)
	{
		discount = 25;
	}
	else if (age < 65)
	{
		discount = 0;
	}
	else 
	{
		discount = 100;
	}

	printf("최종요금 : %d", wage * (100 - discount) / 100);

	return 0;
}