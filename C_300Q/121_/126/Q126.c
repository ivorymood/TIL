#include <stdio.h>

typedef union tagVariable
{
	int i;
	double d;
} VA;

void main(void)
{
	VA va;

	va.i = 5;

	printf("va.i ����ü�� �� : %d \n", va.i);

	va.d = 3.14;

	printf("va.d ����ü�� �� : %f \n", va.d);
	printf("va.i ����ü�� �� : %d \n", va.i);
}