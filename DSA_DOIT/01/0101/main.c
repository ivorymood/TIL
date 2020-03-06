#include <stdio.h>
int max4(int a, int b, int c, int d);
int min3(int a, int b, int c);
int min4(int a, int b, int c, int d);

int main(void)
{
	int a, b, c, d = 0;

	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	scanf_s("%d", &d);

	printf("%d\n", max4(a, b, c, d));
	printf("%d\n", min3(a, b, c));
	printf("%d\n", min4(a, b, c, d));

	return 0;
}

int max4(int a, int b, int c, int d)
{
	int max = a;

	if (b > max) max = b;
	if (c > max) max = c;
	if (d > max) max = d;

	return max;
}

int min3(int a, int b, int c)
{
	int min = a;

	if (b < min) min = b;
	if (c < min) min = c;

	return min;
}

int min4(int a, int b, int c, int d)
{
	int min = a;

	if (b < min) min = b;
	if (c < min) min = c;
	if (d < min) min = d;

	return min;
}