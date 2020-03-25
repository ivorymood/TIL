#include <stdio.h>

int main(void)
{
	int num;

	printf("숫자를 입력하세요 : ");

	scanf_s("%d", &num);

	if (num % 2 == 1)
	{
		printf("%d은 홀수입니다. \n", num);
	}
	else
	{
		printf("%d는 짝수입니다. \n", num);
	}

	return 0;
}