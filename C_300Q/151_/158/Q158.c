#include <stdio.h>

void main(void)
{
	char* oldname = "D:\\file.txt";
	char* newname = "D:\\file_1.txt";

	if (rename(oldname, newname) != 0)
	{
		perror("���ϸ� ���� ����");
	}
	else
	{
		puts("���ϸ��� ���������� ������");
	}
}