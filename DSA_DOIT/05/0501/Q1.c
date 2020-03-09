#include <stdio.h>

int main(void)
{
	int x = 0;
	int result = 1;
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &x);

	for (int i = 1; i <= x; ++i)
	{
		result *= i;
	}

	printf("%d의 순차곱셈 값은 %d 입니다", x, result);

	return 0;
}