#include <stdio.h>
#include <string.h>

void main(void)
{
	char* string = "this is very good!";
	char* strCharSet = "abcdefghijklmnopqrstuvwzyx";
	unsigned int pos;

	pos = strspn(string, strCharSet);

	puts("0         1         2         3");
	puts("0123456789012345678901234567890");
	putchar('\n');
	puts(string);
	puts(strCharSet);

	printf("%d 위치에서 일치되지 않는 문자를 발견하였습니다. \n", pos);
}