#include <stdio.h>
#include <string.h>

#define TOKEN " "

void main(void)
{
	char string[100];
	char* pos;

	puts("���ڿ��� �Է��� �� Enter Ű�� ġ����!");
	gets_s(string, 100);

	pos = strpbrk(string, TOKEN);

	while (pos != NULL)
	{
		puts(pos++);
		pos = strpbrk(pos, TOKEN);
	}
}