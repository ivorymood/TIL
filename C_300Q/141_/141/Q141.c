#include <stdio.h>

void main(void)
{
	FILE* fp;
	int i = 12345;
	int errcd;

	errcd = fopen_s(&fp, "D:\\file.txt", "w+");

	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		fprintf_s(fp, "%d", i);
		fclose(fp);
	}
}