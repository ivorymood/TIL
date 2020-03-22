#include <stdio.h>

void main(void)
{
	FILE* fp;
	int ch;
	int errcd;

	errcd = fopen_s(&fp, "D:\\file.txt", "r");

	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다");
	}
	else
	{
		while (!feof(fp))
		{
			ch = fgetc(fp);
			if (ferror(fp))
			{
				puts("파일을 읽는 중에 에러가 발생했습니다");
			}
			printf("읽은 문자 : %c \n", ch);
		}
		fclose(fp);
	}
}