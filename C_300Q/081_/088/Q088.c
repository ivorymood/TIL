#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	double value;
	char pstr[100];

	value = 3.14e10;
	_gcvt_s(pstr, 100, value, 3);
	printf("��ȯ�� ���ڿ��� %s�Դϴ�. \n", pstr);

	value = -3.14e10;
	_gcvt_s(pstr, 100, value, 2);
	printf("��ȯ�� ���ڿ��� %s�Դϴ�. \n", pstr);
}