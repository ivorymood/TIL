#include <stdio.h>

void main(void)
{
	char* filename = "D:\\file_1.txt";

	if (remove(filename) != 0)
	{
		perror("���� ���� ����");
	}
	else
	{
		puts("������ ���������� ������");
	}
}