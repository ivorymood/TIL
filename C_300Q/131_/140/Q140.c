#include <stdio.h>

void main(void)
{
	FILE* fp;
	char buffer[100];
	unsigned int i_err;

	i_err = fopen_s(&fp, "D:\\file.txt", "r");

	if (fp == NULL)
	{
		printf("���� ���� �� �����ϴ� err: %d\n", i_err);
	}
	else
	{
		fgets(buffer, 100, fp);
		puts(buffer);
		fclose(fp);
	}
}