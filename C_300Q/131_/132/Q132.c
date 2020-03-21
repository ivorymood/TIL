#include <stdio.h>
#include <string.h>

void main(void)
{
	int (*myfunc)(const char*); // 함수 포인터 변수 선언

	myfunc = puts;

	puts("올챙이가 쑥 ~~");
	myfunc("뒷다리가 쏙 ~~");

	myfunc = strlen;

	printf("문자열의 길이 : %d \n", strlen("aa"));
	printf("문자열의 길이 : %d \n", myfunc("aa"));
}