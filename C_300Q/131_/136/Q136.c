#include <stdio.h>

void main(void)
{
	FILE* file;
	unsigned int i_err;

	i_err = fopen_s(&file, "D:\\file.txt", "w+");

	if (file == NULL)
	{
		printf("���� ������ �� �����ϴ� err: %d", i_err);
	}
	else
	{
		printf("���� ������ err: %d", i_err);
		fclose(file);
	}
}