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
		fseek(fp, 0L, SEEK_SET);
		printf("���� �������� ��ġ : %d \n", ftell(fp));
		fseek(fp, -3L, SEEK_END);
		printf("���� �������� ��ġ : %d \n", ftell(fp));
		fseek(fp, -1L, SEEK_CUR);
		printf("���� �������� ��ġ : %d \n", ftell(fp));
		fseek(fp, 4L, SEEK_CUR);
		printf("���� �������� ��ġ : %d \n", ftell(fp));
		fclose(fp);
	}
}