#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int alloc_dyn_array(int size, double default_value, double** ppResult);

int main()
{
	int size = 0;
	double dafault_value = 0;
	double* pArray = NULL;

	printf("������ ������? (0���� Ŀ���մϴ�) \n");
	scanf_s("%d", &size);
	printf("�ʱ갪�� ? \n");
	scanf_s("%lf", &dafault_value);

	int result = alloc_dyn_array(size, dafault_value, &pArray);
	
	if (result != 0) 
	{
		return -1;
	}

	for (int i = 0; i < size; i++)
	{
		printf("%d��° ����? \n", i);
		scanf_s("%lf", pArray + i);
	}

	printf("�Է¹��� ���� ������ �����ϴ�. \n");
	for (int i = 0; i < size; i++)
	{
		printf("%d��°:    %.2lf\n", i, *(pArray + i));
	}

	if (pArray != NULL) free(pArray);

	return 0;
}

int alloc_dyn_array(int size, double default_value, double** ppResult)
{
	if (size <= 0 || default_value < 0 || ppResult == NULL)
	{
		return -1;
	}

	double* pResult = NULL;

	pResult = (double*) malloc(sizeof(double) * size);

	if(pResult != NULL) memset(pResult, default_value, sizeof(double) * size);

	if (pResult == NULL)
	{
		return -1;
	}

	*ppResult = pResult;

	return 0;
}