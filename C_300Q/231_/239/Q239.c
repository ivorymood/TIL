#include <stdio.h>

int main(void)
{
	char* filename = "d:\\file.txt";
	char* movename = "d:\\temp\\file.txt";

	if (rename(filename, movename) != 0)
	{
		perror("���� �̵� ����");
	}
	else
	{
		puts("������ �̵��Ǿ����ϴ�");
	}

	return 0;
}