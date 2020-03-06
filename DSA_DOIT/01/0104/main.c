#include <stdio.h>
int med3(int a, int b, int c);
int med3_2(int a, int b, int c);

int main(void)
{
	int a, b, c = 0;
	
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);

	printf("%d\n", med3(a, b, c));
	printf("%d\n", med3_2(a, b, c));

	return 0;
}

int med3(int a, int b, int c) 
{
	if (a >= b)
	{
		if (b >= c)
		{
			return b;
		}
		else if (c >= a)
		{
			return a;
		}
		else
		{
			return c;
		}
	}
	else
	{
		if (a >= c)
		{
			return a;
		}
		else if (c >= b)
		{
			return b;
		}
		else
		{
			return c;
		}
	}
}

int med3_2(int a, int b, int c)
{
	if ((b >= a && c <= a) || (b <= a && c >= a))
	{
		return a;
	}
	else if ((a > b && c < b) || (a < b && c > b))
	{
		return b;
	}

	return c;
}