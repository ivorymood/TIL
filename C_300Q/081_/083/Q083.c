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
	printf("��ȯ�� ���ڿ��� %s �Դϴ�. \n", string);

	value = -12345;
	_itoa_s(value, string, 100, radix);
	printf("��ȯ�� ���ڿ��� %s �Դϴ�. \n", string);
}