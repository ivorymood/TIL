#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int count;
	int total = 0;
	char string[100];

	for (count = 1; count <= 3; count++)
	{
		printf("%d 번째 문자열을 입력한 후 Enter키를 누르세요 \n", count);
	
		gets_s(string, 100);
	
		total += atoi(string);

		printf("입력 값 = %d, 총 합 = %d \n", atoi(string), total);
	}
	printf("읽은 문자열의 총 합은 %d입니다. \n", total);
}