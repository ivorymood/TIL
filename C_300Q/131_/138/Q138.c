#include <stdio.h>
#include <io.h>

void main(void)
{
	FILE* fp;
	int ch;
	unsigned int i_err;
	char* path = "D:\\file.txt";

	if (_access(path, 6) != 0)
	{
		puts("������ �аų� ���� �����ϴ�");
	}
	else
	{
		puts("������ �аų� ���� �ֽ��ϴ�");
	}

	i_err = fopen_s(&fp, path, "r");

	if (fp == NULL)
	{
		printf("���� ���� �� �����ϴ� err: %d\n", i_err);
	}
	else
	{
		ch = fgetc(fp);
		printf("���� ���� : %c ,  err: %d\n", ch, i_err);
		fclose(fp);
	}
}