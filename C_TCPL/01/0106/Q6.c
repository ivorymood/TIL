#include <stdio.h>

int main()
{
	int c;

	// c 값이 0 / 1 뿐임을 확인
	// ctrl + Z : EOF 확인
	while (c = getchar() != EOF)
	{
		printf("in : %d (%c)\n", c, c);
	}
	printf("last : %d (%c)\n", c, c);
	return 0;
}