#include <stdio.h>

void main(void)
{
	FILE* fp;

	fopen_s(&fp, "D:\\file.txt", "w+");

	fputs("fclose() �Լ�", fp);
	fclose(fp);
}