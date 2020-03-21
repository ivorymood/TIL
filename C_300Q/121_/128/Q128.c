#include <stdio.h>

void main(void)
{
	int i = 50000;
	double d = 3.14;

	int* pi;
	double* pd;
	void* pv;

	pi = &i;
	printf("정수 값 i: %d \n", *pi);
	pd = &d;
	printf("실수 값 d: %f \n", *pd);
	pi = &d; // warning 에러 발생
	printf("정수 값 i: %d \n", *pi);
	pv = &i;
	printf("정수 값 i: %d \n", *(int*)pv);
	pv = &d;
	printf("실수 값 d: %f \n", *(double*) pv);
}