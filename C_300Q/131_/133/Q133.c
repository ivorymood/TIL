#include <stdio.h>
#include <string.h>

void main(void)
{
	int (*myfunc[3])(const char*); // 함수 포인터 배열 선언

	myfunc[0] = puts;
	myfunc[1] = strlen;
	myfunc[2] = myfunc[1];

	puts("올챙이가 쑥 ~~");
	myfunc[0]("뒷다리가 쏙 ~~");

	printf("문자열의 길이 : %d \n", strlen("aa"));
	printf("문자열의 길이 : %d \n", myfunc[1]("aa"));
	printf("문자열의 길이 : %d \n", myfunc[2]("aa"));
}