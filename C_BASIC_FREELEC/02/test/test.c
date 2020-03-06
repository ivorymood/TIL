#include <stdio.h>

int main()
{
	int one = 0, two = 0;

	printf("입력하세요 ");
	scanf_s("%d", &one);
	scanf_s("%d", &two);

	printf("%d   %d", one, two);
	return 0;
}