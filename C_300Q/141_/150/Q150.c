#include <stdio.h>

void main(void)
{
	FILE* fp;
	int errcd;
	fpos_t pos;

	errcd = fopen_s(&fp, "D:\\file.txt", "w+");

	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		fputs("abcde", fp);
		fgetpos(fp, &pos);
		printf("���� �������� ��ġ : %d \n", pos);
		fclose(fp);
	}
}