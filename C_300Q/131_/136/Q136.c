#include <stdio.h>

void main(void)
{
	FILE* file;
	unsigned int i_err;

	i_err = fopen_s(&file, "D:\\file.txt", "w+");

	if (file == NULL)
	{
		printf("파일 생성할 수 없습니다 err: %d", i_err);
	}
	else
	{
		printf("파일 생성됨 err: %d", i_err);
		fclose(file);
	}
}