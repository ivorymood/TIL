#include <stdio.h>

int main(void)
{
	int aList[5][5] = { 0 };
	int nFlag = 1, counter = 0, togle = 1;


	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (nFlag)
			{
				aList[i][j] = ++counter;
			}
			else 
			{
				aList[i][4 - j] = ++counter;
			}
		}
		togle *= -1;
		nFlag += togle;
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