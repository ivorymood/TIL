#include <stdio.h>

void main(void)
{
	int count;
	int tmp;
	int total = 0;

	for (count = 1; count <= 3; ++count)
	{
		printf("%d 번째 정수값을 입력한 후 Enter키를 누르세요 \n", count);

		scanf_s("%d", &tmp);

		total += tmp;

		printf("입력값 : %d, 총 합 = %d \n", tmp, total);
	}

	printf("읽은 정수의 총 합은 %d 입니다 \n", total);
}