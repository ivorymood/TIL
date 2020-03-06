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
		printf("학생 수는? (0 이하의 수를 입력하면 종료됩니다): ");
		scanf_s("%d", &count);

		if (count < 0) 
		{
			return 0;
		}

		pScore = (int*) malloc(sizeof(int) * count);

		if (pScore == NULL) 
		{
			printf("메모리 할당 실패!");
			continue;
		}

		doInput(count, pScore);

		printf("평균 점수는 %lf입니다\n", getAverage(count, pScore));
		printf("다시 입력하세요\n");

		if (pScore != NULL) free(pScore);

	} while (count > 0);

	return 0;
}

void doInput(int count, int* pScore)
{
	if (count <= 0 || pScore == NULL)
	{
		printf("doInput() : 매개변수 오류\n");
		return;
	}

	for (int i = 0; i < count; i++)
	{
		printf("%d번째 학생의 점수는?", i + 1);
		scanf_s("%d", (pScore + i));
	}
}

double getAverage(int count, int* pScore) 
{
	if (count <= 0 || pScore == NULL)
	{
		printf("getAverage() : 매개변수 오류\n");
		return 0;
	}

	double result = 0;
	for (int i = 0; i < count; i++)
	{
		result += *(pScore + i);
	}
	return result / count;
}