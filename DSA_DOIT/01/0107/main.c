#include <stdio.h>
int sum(int num);
int gauss_sum(int num);
int sumof(int a, int b);

int main(void)
{
	int a, b;

	scanf_s("%d", &a);
	scanf_s("%d", &b);

	printf("%d\n", sum(a));
	printf("%d\n", gauss_sum(a));
	printf("%d\n", sumof(a, b));

	return 0;
}

int sum(int num)
{
	int sum = 0;

	for (int i = 1; i <= num; i++)
	{
		sum += i;
	}

	return sum;
}

int gauss_sum(int num)
{
	return (1 + num) * num / 2;
}

int sumof(int a, int b)
{
	int min, max;
	if (a >= b)
	{
		min = b;
		max = a;
	}
	else 
	{
		min = a;
		max = b;
	}

	int sum = 0;

	for (int i = min; i <= max; i++)
	{
		sum += i;
	}

	return sum;
}