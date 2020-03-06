#include <stdio.h>
void minus();
void get_digit();

int main()
{

	


	minus();
	get_digit();

	return 0;
}

void minus()
{
	int a, b = 0;
	printf("a 와 b 입력 \n");
	scanf_s("%d", &a);

	while (1)
	{
		scanf_s("%d", &b);

		if (b <= a)
		{
			break;
		}
			printf("a보다 큰 값을 입력하세요!\n");
	}

	printf("b - a는 %d입니다 \n", b - a);
}

void get_digit()
{
	int num = 0;
	int digit = 0;
	printf("숫자 입력 \n");
	scanf_s("%d", &num);

	while (num > 0)
	{
		digit++;
		num /= 10;
	}

	printf("그 수는 %d자리 입니다. \n", digit);

}