#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	char* string1 = "2�� 1���� Ů�ϴ�.";
	char* string2 = "1004�� õ���Դϴ�.";
	char* string3 = "20000�⵵ �Դϴ�.";
	char* string4 = "������ 6�� 9���Դϴ�.";

	long t1, t2, t3, t4;

	puts(string1);
	puts(string2);
	puts(string3);
	puts(string4);

	t1 = atol(string1);
	t2 = atol(string2);
	t3 = atol(string3);
	t4 = atol(string4);

	printf("���ڿ��� ���ڷ� ��ȯ�� �� : %ld, %ld, %ld, %ld \n", t1, t2, t3, t4);
	printf("�� ���� %d �Դϴ�. ", t1 + t2 + t3 + t4);
}