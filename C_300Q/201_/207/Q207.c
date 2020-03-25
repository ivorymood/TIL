#include <stdio.h>

int main(void)
{
	int i = 127;
	int j;

	printf("%d, %x \n", i, i);
	printf("&i : %#x \n", &i);
	printf("&i : %p \n", &i);
	printf("&j : %#x \n", &j);
	printf("&j : %p \n", &j);

	return 0;
}