#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	char* string = "11000";
	char* stop;
	int radix;
	unsigned long value;

	radix = 2;

	value = strtoul(string, &stop, radix);

	printf("%d ���� ���ڰ� ��ȯ�Ǿ����ϴ�. \n", stop - string);
	printf("16���� %s�� ���ڷ� ��ȯ�ϸ� %u �Դϴ�. \n", string, value);
}