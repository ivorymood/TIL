#include <stdio.h>

void main(void)
{
	FILE* fp;
	int errcd;
	fpos_t pos;

	errcd = fopen_s(&fp, "D:\\file.txt", "w+");

	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		fputs("abcde", fp);
		fgetpos(fp, &pos);
		printf("파일 포인터의 위치 : %d \n", pos);
		fclose(fp);
	}
}