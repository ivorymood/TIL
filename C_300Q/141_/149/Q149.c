#include <stdio.h>

void main(void)
{
	FILE* fp;
	int errcd;

	errcd = fopen_s(&fp, "D:\\file.txt", "r");

	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		fseek(fp, 0L, SEEK_END);
		printf("���� �������� ��ġ : %d \n", ftell(fp));
		fclose(fp);
	}
}