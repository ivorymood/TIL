#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	double value;
	char pstr[100];
	int dec, sign;

	value = 3.1415926535;
	_fcvt_s(pstr, 100, value, 6, &dec, &sign);

	printf("변환된 문자열은 %s입니다. \n", pstr);
	printf("소수점의 위치는 %d, 부호는 %d입니다.\n", dec, sign);

	value = -3.1415926535;
	_fcvt_s(pstr, 100, value, 8, &dec, &sign);

	printf("변환된 문자열은 %s입니다. \n", pstr);
	printf("소수점의 위치는 %d, 부호는 %d입니다.\n", dec, sign);
}