#include <stdio.h>

int main()
{
	char char_value = 'C';
	int int_value = 100;
	double double_value = 100.5;

	// 포인터 변수, 변수크기, 주소, 가리키는 변수의 값

	char* pchar_value = NULL;
	int* pint_value = NULL;
	double* pdouble_value = NULL;

	pchar_value = &char_value;
	pint_value = &int_value;
	pdouble_value = &double_value;

	printf("char 변수크기 : %d \t 주소 : %p \t 변수 값 : %c \n"
		,  sizeof(pchar_value), pchar_value, *pchar_value);

	printf("int  변수크기 : %d \t 주소 : %p \t 변수 값 : %d \n"
		,  sizeof(pint_value), pint_value, *pint_value);

	printf("double  변수크기 : %d \t 주소 : %p \t 변수 값 : %f \n"
		,  sizeof(pdouble_value), pdouble_value, *pdouble_value);

	printf("%p , %p  \n", pdouble_value, &pdouble_value);
	return 0;
}