#include <stdio.h>

int main()
{
	int c;

	// c ���� 0 / 1 ������ Ȯ��
	// ctrl + Z : EOF Ȯ��
	while (c = getchar() != EOF)
	{
		printf("in : %d (%c)\n", c, c);
	}
	printf("last : %d (%c)\n", c, c);
	return 0;
}