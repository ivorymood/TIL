#include <stdio.h>
#include <time.h>

void main(void)
{
	time_t now;
	struct tm t;

	time(&now);

	gmtime_s(&t, &now);

	printf("현재 날짜 및 시간 : %4d.%d.%d %d:%d:%d \n",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec);
}