#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	double value;
	char pstr[100];

	value = 3.14e10;
	_gcvt_s(pstr, 100, value, 3);
	printf("변환된 문자열은 %s입니다. \n", pstr);

	value = -3.14e10;
	_gcvt_s(pstr, 100, value, 2);
	printf("변환된 문자열은 %s입니다. \n", pstr);
}