#include <stdio.h>

void main(void)
{
	char* p_char;
	short* p_short;
	int* p_int;
	long* p_long;
	float* p_float;
	double* p_double;

	printf("c문자형의 크기 : %d 바이트 \n", sizeof(char));
	printf("s정수형의 크기 : %d 바이트 \n", sizeof(short));
	printf("i정수형의 크기 : %d 바이트 \n", sizeof(int));
	printf("l정수형의 크기 : %d 바이트 \n", sizeof(long));
	printf("f실수형의 크기 : %d 바이트 \n", sizeof(float));
	printf("d실수형의 크기 : %d 바이트 \n", sizeof(double));
	
	printf("c문자형 포인터의 크기 : %d 바이트 \n", sizeof(p_char));
	printf("s정수형 포인터의 크기 : %d 바이트 \n", sizeof(p_short));
	printf("i정수형 포인터의 크기 : %d 바이트 \n", sizeof(p_int));
	printf("l정수형 포인터의 크기 : %d 바이트 \n", sizeof(p_long));
	printf("f실수형 포인터의 크기 : %d 바이트 \n", sizeof(p_float));
	printf("d실수형 포인터의 크기 : %d 바이트 \n", sizeof(p_double));
}