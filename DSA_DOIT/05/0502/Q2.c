#include <stdio.h>

int main(void)
{
	int x, y;
	puts("두 정수의 최대공약수를 구합니다.");
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &x);
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &y);

	while (y > 0)
	{
		int temp = y;
		y = x % y;
		x = temp;
	}

	printf("최대공약수는 %d입니다.\n", x);

	return 0;
}