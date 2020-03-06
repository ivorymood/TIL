#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** alloc_dyn_array(int nRow, int nCol);
void input_array(int **ppResult, int nRow, int nCol);
void print_array(int **ppResult, int nRow, int nCol);
void free_dyn_array(int **ppResult, int nRow);

int get_max_value(int** ppResult, int nRow, int nCol);
int get_min_value(int** ppResult, int nRow, int nCol);

int main()
{
	int row = 0, col = 0;
	int** ppArray = NULL;

	printf("행 입력");
	scanf_s("%d", &row);
	printf("열 입력");
	scanf_s("%d", &col);

	if (row <= 0 || col <= 0)
	{
		return -1;
	}

	ppArray = alloc_dyn_array(row, col);

	if (ppArray == NULL)
	{
		return -1;
	}

	input_array(ppArray, row, col);
	print_array(ppArray, row, col);

	printf("최댓값: %d\n", get_max_value(ppArray, row, col));
	printf("최솟값: %d\n", get_min_value(ppArray, row, col));

	free_dyn_array(ppArray, row);
}

int** alloc_dyn_array(int nRow, int nCol)
{
	if (nRow <= 0 || nCol <= 0) 
	{
		return NULL;
	}

	int** ppResult = NULL;

	ppResult = (int**)malloc(sizeof(int*) * nRow);

	for (int i = 0; i < nRow; i++)
	{
		ppResult[i] = (int*)malloc(sizeof(int) * nCol);
	}

	return ppResult;
}

void input_array(int** ppResult, int nRow, int nCol)
{
	if (ppResult == NULL || nRow <= 0 || nCol <= 0)
	{
		return;
	}

	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			printf("[%d][%d]값은? ", i, j);
			scanf_s("%d", &ppResult[i][j]);
		}
	}
}

void print_array(int** ppResult, int nRow, int nCol)
{
	if (ppResult == NULL || nRow <= 0 || nCol <= 0)
	{
		return;
	}

	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			printf("%d ", ppResult[i][j]);
		}
		printf("\n");
	}
}

void free_dyn_array(int** ppResult, int nRow)
{
	if (ppResult == NULL || nRow <= 0)
	{
		return;
	}

	for (int i = 0; i < nRow; i++)
	{
		if (ppResult[i] != NULL) free(ppResult[i]);
		ppResult[i] = NULL;
	}
	
	if (ppResult != NULL) free(ppResult);
	ppResult = NULL;
}

int get_max_value(int** ppResult, int nRow, int nCol)
{
	if (ppResult == NULL || nRow <= 0 || nCol <= 0)
	{
		return -1;
	}

	int max = ppResult[0][0];

	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			if (max < ppResult[i][j])
			{
				max = ppResult[i][j];
			}
		}
	}
	return max;
}
int get_min_value(int** ppResult, int nRow, int nCol)
{
	if (ppResult == NULL || nRow <= 0 || nCol <= 0)
	{
		return -1;
	}

	int min = ppResult[0][0];

	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			if (min > ppResult[i][j])
			{
				min = ppResult[i][j];
			}
		}
	}
	return min;
}