#include <stdio.h>

void main(void)
{
	FILE* fp;
	int errcd;

	errcd = fopen_s(&fp, "D:\\file.txt", "w+");

	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		fputs("���ѹα�", fp);
		fflush(fp);
		fclose(fp);
	}
}