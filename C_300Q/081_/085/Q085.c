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
	printf("��ȯ�� ���ڿ��� %s �Դϴ�. \n", string);

	value = 1234567890;
	_itoa_s(value, string, 100, radix);
	printf("��ȯ�� ���ڿ��� %s �Դϴ�. \n", string);
}