#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int value;
	char string[100];
	int radix;

	radix = 10;

	value = 5;
	_itoa_s(value, string, 100, radix);
	printf("변환된 문자열은 %s 입니다. \n", string);

	value = -12345;
	_itoa_s(value, string, 100, radix);
	printf("변환된 문자열은 %s 입니다. \n", string);
}