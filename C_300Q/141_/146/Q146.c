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
		printf("���� �������� ��ġ : %d \n", ftell(fp));
		fputs("abcde", fp);
		printf("���� �������� ��ġ : %d \n", ftell(fp));
		rewind(fp);
		printf("���� �������� ��ġ : %d \n", ftell(fp));
		fclose(fp);
	}
}