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

	printf("%d ��ġ���� ��ġ���� �ʴ� ���ڸ� �߰��Ͽ����ϴ�. \n", pos);
}