#include <stdio.h>

int main(void)
{
	int aList[5][5] = { 0 };
	int side = 5;
	int x = 0, y = -1;
	int d = 1;
	int counter = 0;
	

	for (int nLimit = 2 * side - 1; nLimit > 0; nLimit -= 2)
	{
		for (int i = 0; i < nLimit; ++i)
		{
			if (i <= nLimit / 2)
			{
				y += d;
			}
			else
			{
				x += d;
			}
			aList[x][y] = ++counter;
		}
		d *= -1;
	}


	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			printf("%d\t", aList[i][j]);
		}
		putchar('\n');
	}

	return 0;
}