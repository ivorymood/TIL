#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>

int main(void)
{
	struct tm christmas = { 0, 0, 0, 25, 12 - 1, 2020 - 1900 };
	char* wday[] = {"일", "월", "화", "수", "목", "금", "토"};
	char buff[100];

	mktime(&christmas);

	strftime(buff, sizeof buff, "2020년 12월 25일은 %A입니다.", &christmas);

	puts(buff);
	printf("2020년 12월 25일은 %s요일 입니다.\n", wday[christmas.tm_wday]);

	return 0;
}