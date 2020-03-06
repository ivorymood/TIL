#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���� �����ͷ� �ִ� �ּڰ� ���ϱ�
void get_max_min_pointer(int*, int, int**, int**);

int main()
{
	int count = 0;
	int* pint_value = NULL;
	int* pmax_value = NULL;
	int* pmin_value = NULL;

	printf("�迭�� ������? (0���� Ŀ���մϴ�)\n");
	scanf_s("%d", &count);

	pint_value = malloc(sizeof(int) * count);

	if (pint_value == NULL)
	{
		return 0;
	}

	memset(pint_value, 0, sizeof(int) * count);

	for (int i = 0; i < count; i++)
	{
		printf("%d��° ����?\n", i);
		scanf_s("%d", pint_value + i);
	}

	get_max_min_pointer(pint_value, count, &pmax_value, &pmin_value);

	printf("�ִ� ������ �ּ�: %p, ��: %d\n", pmax_value, *pmax_value);
	printf("�ּ� ������ �ּ�: %p, ��: %d\n", pmin_value, *pmin_value);

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