#include <stdio.h>

void main(void)
{
	int i = 50000;
	double d = 3.14;

	int* pi;
	double* pd;
	void* pv;

	pi = &i;
	printf("���� �� i: %d \n", *pi);
	pd = &d;
	printf("�Ǽ� �� d: %f \n", *pd);
	pi = &d; // warning ���� �߻�
	printf("���� �� i: %d \n", *pi);
	pv = &i;
	printf("���� �� i: %d \n", *(int*)pv);
	pv = &d;
	printf("�Ǽ� �� d: %f \n", *(double*) pv);
}