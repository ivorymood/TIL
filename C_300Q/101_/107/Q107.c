#include <stdio.h>

void change_x1(int x1);
void change_x2(int* x2);

void main(void)
{
	int x;
	x = 5;
	printf("�Լ��� ȣ���ϱ� �� x�� : %d \n", x);

	change_x1(x);
	printf("change_x1() �Լ��� ȣ���� ���� x�� : %d \n", x);

	change_x2(&x);
	printf("change_x2() �Լ��� ȣ���� ���� x�� : %d \n", x);
}

void change_x1(int x1)
{
	x1 = 50;
}

void change_x2(int* x2)
{
	*x2 = 100;
}