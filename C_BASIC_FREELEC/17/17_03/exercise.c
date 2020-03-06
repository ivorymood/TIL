#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(int value1, int value2);
void subtract(int value1, int value2);
void multiply(int value1, int value2);

void (*do_calc[])(int value1, int value2) = { add, subtract, multiply };

int main(int argc, char **argv)
{
	int type = atoi(argv[1]);

	if (argc != 4 || type > 3 || type < 0)
	{
		printf("사용방법: 17_04.exe [연산종류: 1-더하기, 2-빼기, 3-곱하기] [숫자1] [숫자2]\n");
		return 0;
	}

	do_calc[type - 1](atoi(argv[2]), atoi(argv[3]));

	return 0;
}

void add(int value1, int value2)
{
	printf("%d + %d = %d", value1, value2, value1 + value2);
}

void subtract(int value1, int value2)
{
	printf("%d - %d = %d", value1, value2, value1 - value2);
}

void multiply(int value1, int value2)
{
	printf("%d * %d = %d", value1, value2, value1 * value2);
}