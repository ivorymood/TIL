#include <stdio.h>

// 정수를 입력해 주세요 ? 5
// 1부터 5까지의 정수의 합은 15입니다
// int n입력 받아서 1~n까지 더하는 프로그램

int sum_recursive(int);

int main()
{
	int input = 0;
	int sum = 0;

	printf("정수를 입력해 주세요 ?");
	scanf_s("%d", &input);

	sum = sum_recursive(input);

	printf("1부터 %d까지의 정수의 합은 %d입니다",input, sum);

	return 0;
}

int sum_recursive(int n)
{
	int sum = 0;

	if (n <= 1) 
	{
		return 1;
	}

	sum += n + sum_recursive(n - 1);

	return sum;
}