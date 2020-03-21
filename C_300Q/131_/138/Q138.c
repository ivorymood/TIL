#include <stdio.h>
#include <io.h>

void main(void)
{
	FILE* fp;
	int ch;
	unsigned int i_err;
	char* path = "D:\\file.txt";

	if (_access(path, 6) != 0)
	{
		puts("파일을 읽거나 쓸수 없습니다");
	}
	else
	{
		puts("파일을 읽거나 쓸수 있습니다");
	}

	i_err = fopen_s(&fp, path, "r");

	if (fp == NULL)
	{
		printf("파일 읽을 수 없습니다 err: %d\n", i_err);
	}
	else
	{
		ch = fgetc(fp);
		printf("읽은 문자 : %c ,  err: %d\n", ch, i_err);
		fclose(fp);
	}
}