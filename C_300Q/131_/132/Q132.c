#include <stdio.h>
#include <string.h>

void main(void)
{
	int (*myfunc)(const char*); // �Լ� ������ ���� ����

	myfunc = puts;

	puts("��ì�̰� �� ~~");
	myfunc("�޴ٸ��� �� ~~");

	myfunc = strlen;

	printf("���ڿ��� ���� : %d \n", strlen("aa"));
	printf("���ڿ��� ���� : %d \n", myfunc("aa"));
}