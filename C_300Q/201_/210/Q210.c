#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int radix = 16;
	int base = 2;
	char string[] = "10101011";
	char* stop;
	long value;
	char buff[100];

	value = strtol(string, &stop, base);
	_itoa_s(value, buff, sizeof(buff), radix);
	puts(buff);

	return 0;
}