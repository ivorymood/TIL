#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	double value;
	char pstr[100];
	int dec, sign;

	value = 3.1415926535;
	_fcvt_s(pstr, 100, value, 6, &dec, &sign);

	printf("��ȯ�� ���ڿ��� %s�Դϴ�. \n", pstr);
	printf("�Ҽ����� ��ġ�� %d, ��ȣ�� %d�Դϴ�.\n", dec, sign);

	value = -3.1415926535;
	_fcvt_s(pstr, 100, value, 8, &dec, &sign);

	printf("��ȯ�� ���ڿ��� %s�Դϴ�. \n", pstr);
	printf("�Ҽ����� ��ġ�� %d, ��ȣ�� %d�Դϴ�.\n", dec, sign);
}