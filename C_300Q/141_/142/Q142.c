#include <stdio.h>

void main(void)
{
	FILE* fp;
	int i;
	int errcd;
	char string[10] = {0};

	errcd = fopen_s(&fp, "D:\\file.txt", "r");

	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		//fscanf_s(fp, "%d", &i);
		fscanf_s(fp, "%s", string, 10);
		//printf("i : %d\n", i);
		printf("s : %s\n", string);
		fclose(fp);
	}
}