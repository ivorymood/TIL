#include <stdio.h>

int main(void)
{
	int i = 0;
	int j = 0;

	while (i < 5)
	{
		while (j < 5)
		{
			printf("%c\t", '*');
			j++;
		}
		j = 0;
		printf("\n");
		i++;
	}

	return 0;
}