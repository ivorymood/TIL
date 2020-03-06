#include <stdio.h>

//피보나치 n번째 요소 구하기
// 0 1 ...

//정수를 입력해 주세요?
//피보나치 수열에서 d번째 요소는 5입니다. 

int fibonacci_recursive(int);

int main()
{
	int input = 0;
	int num = 0;

	printf("정수를 입력해 주세요?");
	scanf_s("%d", &input);

	num = fibonacci_recursive(input);

	printf("피보나치 수열에서 %d번째 요소는 %d입니다. ", input, num);

	return 0;
}

int fibonacci_recursive(int n)
{
	int sum = 0;

	if (n <= 2)
	{
		return n - 1;
	}

	sum = fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);

	return sum;
}