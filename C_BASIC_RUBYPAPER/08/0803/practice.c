#include <stdio.h>

int main(void)
{
	int aList[3][4] = {
		{10, 20, 30},
		{40, 50, 60}
	};
	int i = 0, j = 0;

	int last_i = sizeof(aList) / sizeof(aList[0]) - 1;
	int last_j = sizeof(aList[0]) / sizeof(int) - 1;

	printf("%d\n", last_i);

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 4; ++j)
		{
			if (j != last_j)
			{
				aList[i][last_j] += aList[i][j];

				if (i != last_i)
				{
					aList[last_i][j] += aList[i][j];
				}
			}
		}
	}

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 4; ++j)
		{
			printf("%d\t", aList[i][j]);
		}
		putchar('\n');
	}

	return 0;
}