#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int value;
	char string[100];
	int radix;

	radix = 16;

	value = 34567;
	_itoa_s(value, string, 100, radix);
	printf("변환된 문자열은 %s 입니다. \n", string);

	value = 1234567890;
	_itoa_s(value, string, 100, radix);
	printf("변환된 문자열은 %s 입니다. \n", string);
}