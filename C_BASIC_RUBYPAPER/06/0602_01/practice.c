#include <stdio.h>

int main(void)
{
	int age = 0;
	int wage = 1000;
	int discount = 0;

	printf("���� �Է� : ");
	scanf_s("%d", &age);

	if (age < 14)
	{
		if (age < 4)
		{
			discount = 100;
		}
		else
		{
			discount = 50;
		}
	}
	else
	{
		if (age < 20)
		{
			discount = 25;
		}
		else
		{
			discount = 0;
		}
	}

	printf("������� : %d", wage * (100 - discount) / 100);

	return 0;
}