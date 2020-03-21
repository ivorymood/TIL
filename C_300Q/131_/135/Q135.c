#include <stdio.h>

int main(int argc, int* argv[])
{
	int i;

	printf("인수의 수 : %d \n", argc);

	for (i = 0; i < argc; i++)
	{
		printf("argc[%d] : %s \n", i, argv[i]);
	}

	return 0;
}