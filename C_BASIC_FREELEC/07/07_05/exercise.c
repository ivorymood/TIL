#include <stdio.h>

int input_score()
{
	int score = 0;
	printf("점수는 얼마인가요(음수면 종료)?");
	scanf_s("%d", &score);
	return score;
}

double update_avarage(int score)
{
	static int sum = 0;
	static int count = 0;

	sum += score;
	count++;

	return (double) sum / count;
}

void print_result(int count, double average)
{
	printf("현재까지 입력 횟수: %d, 평균: %f \n", count, average);
}

int main() 
{
	int score = 0;
	int count = 0;
	double average = 0;

	while (1)
	{
		score = input_score();
		if (score < 0)
		{
			break;
		}

		count++;

		average = update_avarage(score);
		print_result(count, average);
	}

	return 0;
}