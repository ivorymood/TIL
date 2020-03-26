#include <stdio.h>
#include <string.h>

int main(void)
{
	char string[] = "abcdefghijklmnopqrstuvwxyz";
	unsigned i, len;

	puts(string);

	len = strlen(string);

	for (i = 0; i < len; ++i)
	{
		string[i] = string[i] & 0xDF;	// string[i] = string[i] - 32 ¿Í µ¿ÀÏ
	}

	puts(string);

	return 0;
}