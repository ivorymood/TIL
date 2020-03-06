#include <stdio.h>

int main(void)
{
	int x = 0, y = 0;

	printf("두 정수를 입력하세요 : ");
	scanf_s("%d", &x);
	scanf_s("%d", &y);

	printf("AVG : %.2f", (x + y) / 2.0);

	return 0;
}