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
		fputs("ABC", fp);
		printf("���ڿ� \"ABC\"�� ���Ͽ� ������ err: %d\n", i_err);
		fclose(fp);
	}
}