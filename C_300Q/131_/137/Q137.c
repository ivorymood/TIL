#include <stdio.h>

void main(void)
{
	FILE* fp;
	unsigned int i_err;

	i_err = fopen_s(&fp, "D:\\file.txt", "w+");

	if (fp == NULL)
	{
		printf("���� ������ �� �����ϴ� err: %d\n", i_err);
	}
	else
	{
		printf("���� ������ err: %d\n", i_err);
		fputc('A', fp);
		printf("���� 'A'�� ���Ͽ� ������ err: %d\n", i_err);
		fclose(fp);
	}
}