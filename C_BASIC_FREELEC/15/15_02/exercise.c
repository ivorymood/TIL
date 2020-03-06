#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//더블 포인터로 최댓값 최솟값 구하기
void get_max_min_pointer(int*, int, int**, int**);

int main()
{
	int count = 0;
	int* pint_value = NULL;
	int* pmax_value = NULL;
	int* pmin_value = NULL;

	printf("배열의 개수는? (0보다 커야합니다)\n");
	scanf_s("%d", &count);

	pint_value = malloc(sizeof(int) * count);

	if (pint_value == NULL)
	{
		return 0;
	}

	memset(pint_value, 0, sizeof(int) * count);

	for (int i = 0; i < count; i++)
	{
		printf("%d번째 값은?\n", i);
		scanf_s("%d", pint_value + i);
	}

	get_max_min_pointer(pint_value, count, &pmax_value, &pmin_value);

	printf("최대 원소의 주소: %p, 값: %d\n", pmax_value, *pmax_value);
	printf("최소 원소의 주소: %p, 값: %d\n", pmin_value, *pmin_value);

	if (pint_value != NULL) free(pint_value);

	return 0;
}

void get_max_min_pointer(int* pint_values, int count, int** ppmax_value, int** ppmin_value)
{
	int* pmax = pint_values;
	int* pmin = pint_values;

	if (pint_values == NULL || ppmax_value == NULL || ppmin_value == NULL || count <= 0)
	{
		return;
	}

	for (int i = 0; i < count; i++)
	{
		if (*pmax < *(pint_values + i))
		{
			pmax = pint_values + i;
		}
		if (*pmin > *(pint_values + i))
		{
			pmin = pint_values + i;
		}
	}

	*ppmax_value = pmax;
	*ppmin_value = pmin;
}