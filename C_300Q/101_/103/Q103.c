#include <stdio.h>
#include <string.h>

void main(void)
{
	char string[50] = "�Ƹ��ٿ� �츮���� ���ѹα�";

	puts(string);

	memset(string, (int)NULL, sizeof(string));

	puts(string);

	memset(string, '*', sizeof(string) - 1);

	puts(string);
}