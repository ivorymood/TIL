#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	double value;
	char pstr[100];
	int dec, sign;

	value = 3.14e10;
	_ecvt_s(pstr, 100, value, 3, &dec, &sign);

	printf("��ȯ�� ���ڿ��� %s�Դϴ�. \n", pstr);
	printf("�Ҽ����� ��ġ�� %d, ��ȣ�� %d�Դϴ�.\n", dec, sign);

	value = -3.14e10;
	_ecvt_s(pstr, 100, value, 4, &dec, &sign);

	printf("��ȯ�� ���ڿ��� %s�Դϴ�. \n", pstr);
	printf("�Ҽ����� ��ġ�� %d, ��ȣ�� %d�Դϴ�.\n", dec, sign);
}