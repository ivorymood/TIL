#include <stdio.h>

void main(void)
{
	char* p_char;
	short* p_short;
	int* p_int;
	long* p_long;
	float* p_float;
	double* p_double;

	printf("c�������� ũ�� : %d ����Ʈ \n", sizeof(char));
	printf("s�������� ũ�� : %d ����Ʈ \n", sizeof(short));
	printf("i�������� ũ�� : %d ����Ʈ \n", sizeof(int));
	printf("l�������� ũ�� : %d ����Ʈ \n", sizeof(long));
	printf("f�Ǽ����� ũ�� : %d ����Ʈ \n", sizeof(float));
	printf("d�Ǽ����� ũ�� : %d ����Ʈ \n", sizeof(double));
	
	printf("c������ �������� ũ�� : %d ����Ʈ \n", sizeof(p_char));
	printf("s������ �������� ũ�� : %d ����Ʈ \n", sizeof(p_short));
	printf("i������ �������� ũ�� : %d ����Ʈ \n", sizeof(p_int));
	printf("l������ �������� ũ�� : %d ����Ʈ \n", sizeof(p_long));
	printf("f�Ǽ��� �������� ũ�� : %d ����Ʈ \n", sizeof(p_float));
	printf("d�Ǽ��� �������� ũ�� : %d ����Ʈ \n", sizeof(p_double));
}