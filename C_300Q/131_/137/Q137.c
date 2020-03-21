#include <stdio.h>

void main(void)
{
	FILE* fp;
	unsigned int i_err;

	i_err = fopen_s(&fp, "D:\\file.txt", "w+");

	if (fp == NULL)
	{
		printf("파일 생성할 수 없습니다 err: %d\n", i_err);
	}
	else
	{
		printf("파일 생성됨 err: %d\n", i_err);
		fputc('A', fp);
		printf("문자 'A'를 파일에 저장함 err: %d\n", i_err);
		fclose(fp);
	}
}