#include <stdio.h>

void main(void)
{
	FILE* fp;
	fpos_t pos;
	int errcd;

	errcd = fopen_s(&fp, "D:\\file.txt", "w+");

	fgetpos(fp, &pos);
	fputs("abcde", fp);
	fsetpos(fp, &pos);
	printf("���� �������� ��ġ : %d \n", ftell(fp));
	fclose(fp);
}