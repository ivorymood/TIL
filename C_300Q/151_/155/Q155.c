#include <stdio.h>

void main(void)
{
	FILE* fp;
	int ch;
	int errcd;

	errcd = fopen_s(&fp, "D:\\no_file.txt", "r");

	if (fp == NULL)
	{
		perror("���� ���� ����");
	}
	else
	{
		ch = fgetc(fp);
		if (ferror(fp))
		{
			perror("���� �б� ����");
		}
		fclose(fp);
	}
}