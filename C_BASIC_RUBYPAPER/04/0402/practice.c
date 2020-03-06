#include <stdio.h>

int main(void)
{
	int hour, min, second = 0;

	printf("초 입력 : ");
	scanf_s("%d", &second);

	hour = second / 3600;
	min = second % 3600 / 60;
	second = second % 60;
	
	printf("%d 초는 %02d시간 %02d분 %02d초 입니다. ", second, hour, min, second);


	return 0;
}