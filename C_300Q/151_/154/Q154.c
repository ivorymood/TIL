#include <stdio.h>

void main(void)
{
	FILE* fp;
	int ch;
	int errcd;

	errcd = fopen_s(&fp, "D:\\file.txt", "r");

	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�");
	}
	else
	{
		while (!feof(fp))
		{
			ch = fgetc(fp);
			if (ferror(fp))
			{
				puts("������ �д� �߿� ������ �߻��߽��ϴ�");
			}
			printf("���� ���� : %c \n", ch);
		}
		fclose(fp);
	}
}