#include <stdio.h>

int main(void)
{
	printf("test\n");
	int int_value = 0;
	printf("곱하기 연산결과 \n");
	int_value = 2 * 3;
	printf("2 * 3 = %d\n", int_value);


	system("pause");



	printf("\n-- General Data Type Size --\n");

	printf("char size : %d byte\n", (int)sizeof(char));

	printf("short size : %d byte\n", (int)sizeof(short));

	printf("int size : %d byte\n", (int)sizeof(int));

	printf("long size : %d byte\n", (int)sizeof(long));

	printf("double size : %d byte\n", (int)sizeof(double));

	printf("long double size : %d byte\n", (int)sizeof(long double));



	printf("\n-- Pointer Data Type Size -- \n");

	printf("char* size : %d byte\n", (int)sizeof(char*));

	printf("short* size : %d byte\n", (int)sizeof(short*));

	printf("int* size : %d byte\n", (int)sizeof(int*));

	printf("long* size : %d byte\n", (int)sizeof(long*));

	printf("double* size : %d byte\n", (int)sizeof(double*));

	printf("long double* size : %d byte\n", (int)sizeof(long double*));
	return 0;
}