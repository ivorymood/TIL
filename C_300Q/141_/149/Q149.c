#include <stdio.h>

void main(void)
{
	FILE* fp;
	int errcd;

	errcd = fopen_s(&fp, "D:\\file.txt", "r");

	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		fseek(fp, 0L, SEEK_END);
		printf("파일 포인터의 위치 : %d \n", ftell(fp));
		fclose(fp);
	}
}