#include <stdio.h>
#include <stdlib.h>

void doInput(int, int*);
double getAverage(int, int*);

int main()
{
	int count = 0;
	int* pScore = NULL;
	double average = 0;

	do 
	{
		printf("�л� ����? (0 ������ ���� �Է��ϸ� ����˴ϴ�): ");
		scanf_s("%d", &count);

		if (count < 0) 
		{
			return 0;
		}

		pScore = (int*) malloc(sizeof(int) * count);

		if (pScore == NULL) 
		{
			printf("�޸� �Ҵ� ����!");
			continue;
		}

		doInput(count, pScore);

		printf("��� ������ %lf�Դϴ�\n", getAverage(count, pScore));
		printf("�ٽ� �Է��ϼ���\n");

		if (pScore != NULL) free(pScore);

	} while (count > 0);

	return 0;
}

void doInput(int count, int* pScore)
{
	if (count <= 0 || pScore == NULL)
	{
		printf("doInput() : �Ű����� ����\n");
		return;
	}

	for (int i = 0; i < count; i++)
	{
		printf("%d��° �л��� ������?", i + 1);
		scanf_s("%d", (pScore + i));
	}
}

double getAverage(int count, int* pScore) 
{
	if (count <= 0 || pScore == NULL)
	{
		printf("getAverage() : �Ű����� ����\n");
		return 0;
	}

	double result = 0;
	for (int i = 0; i < count; i++)
	{
		result += *(pScore + i);
	}
	return result / count;
}