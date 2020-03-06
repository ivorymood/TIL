#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void do_input(int (*pmy_int_values)[4], int row_count);
int get_max_value(int (*pmy_int_values)[4], int row_count);

int main()
{
	int int_values[2][4] = {0};

	do_input(int_values, sizeof(int_values) / sizeof(int[4]));

	printf("ÃÖ´ñ°ª: %d\n", get_max_value(int_values, sizeof(int_values) / sizeof(int[4])));

	return 0;
}

void do_input(int (*pmy_int_values)[4], int row_count) {

	if (pmy_int_values == NULL || row_count < 0)
	{
		return;
	}

	for (int i = 0; i < row_count; i++)
	{
		for (int j = 0; j < sizeof(*pmy_int_values) / sizeof(int*); j++)
		{
			printf("[%d][%d]´Â ? ", i, j);
			scanf_s("%d", &pmy_int_values[i][j]);
		}
		printf("\n");
	}
}

int get_max_value(int (*pmy_int_values)[4], int row_count) {

	if (pmy_int_values == NULL || row_count < 0)
	{
		return -1;
	}

	int max = pmy_int_values[0][0];

	for (int i = 0; i < row_count; i++)
	{
		for (int j = 0; j < sizeof(*pmy_int_values) / sizeof(int*); j++)
		{
			if (pmy_int_values[i][j] > max)
			{
				max = pmy_int_values[i][j];
			}
		}
	}
	return max;
}