#include <stdio.h>
#include <string.h>

void main(void)
{
	char* string = "This is a sztring $$$";
	char* strCharSet = "~!@#$%^&*()_+-={}[]:;'<>./?";
	char* strCharSet_2 = "xyz";
	unsigned int pos;
	unsigned int pos_2;

	pos = strcspn(string, strCharSet);
	pos_2 = strcspn(string, strCharSet_2);

	puts("0         1         2         3");
	puts("0123456789012345678901234567890");
	putchar('\n');
	puts(string);
	puts(strCharSet);

	printf("1: %d 위치에서 일치되는 첫 문자를 발견하였습니다. \n", pos);
	printf("2: %d 위치에서 일치되는 첫 문자를 발견하였습니다. \n", pos_2);
}