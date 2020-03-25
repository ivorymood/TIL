#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char buff[100];
	int radix = 16;

	_itoa_s(10, buff, sizeof(buff), radix);
	puts(buff);

	_itoa_s(9, buff, sizeof(buff), radix);
	puts(buff);

	_itoa_s(255, buff, sizeof(buff), radix);
	puts(buff);

	return 0;
}