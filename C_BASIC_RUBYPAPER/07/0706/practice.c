#include <stdio.h>

int main(void)
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (i + j >= 4)
			{
				printf("%c\t", '*');
			}
			else
			{
				printf("\t");
			}
		}
		printf("\n");
	}

	return 0;
}