#include <stdio.h>

void main(void)
{
	FILE* fp;

	fopen_s(&fp, "D:\\file.txt", "w+");

	fputs("fclose() ÇÔ¼ö", fp);
	fclose(fp);
}