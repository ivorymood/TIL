#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char string1[] = "1010";
	char string2[] = "ff";
	char* stop;
	long value;

	value = strtol(string1, &stop, 2);
	printf("2�� ���ڿ� \"%s\"�� ������ �ٲٸ� %d�Դϴ�. \n", string1, value);

	value = strtol(string2, &stop, 16);
	printf("16�� ���ڿ� \"%s\"�� ������ �ٲٸ� %d�Դϴ�. \n", string1, value);

	return 0;
}