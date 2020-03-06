#include <stdio.h>

int main(void)
{
	int nMax = 0;
	int a, b, c;

	printf("3 ¼ö ÀÔ·Â ");
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);

	nMax = a;
	nMax = (b > nMax) ? b : nMax;
	nMax = (c > nMax) ? c : nMax;

	printf("MAX : %d\n", nMax);
	return 0;
}