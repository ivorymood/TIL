#include <stdio.h>

int main()
{
	char char_value = 'C';
	int int_value = 100;
	double double_value = 100.5;

	// ������ ����, ����ũ��, �ּ�, ����Ű�� ������ ��

	char* pchar_value = NULL;
	int* pint_value = NULL;
	double* pdouble_value = NULL;

	pchar_value = &char_value;
	pint_value = &int_value;
	pdouble_value = &double_value;

	printf("char ����ũ�� : %d \t �ּ� : %p \t ���� �� : %c \n"
		,  sizeof(pchar_value), pchar_value, *pchar_value);

	printf("int  ����ũ�� : %d \t �ּ� : %p \t ���� �� : %d \n"
		,  sizeof(pint_value), pint_value, *pint_value);

	printf("double  ����ũ�� : %d \t �ּ� : %p \t ���� �� : %f \n"
		,  sizeof(pdouble_value), pdouble_value, *pdouble_value);

	printf("%p , %p  \n", pdouble_value, &pdouble_value);
	return 0;
}