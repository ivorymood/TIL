#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>

void main(void)
{
	struct _timeb tb;
	struct tm t;

	_ftime64_s(&tb);

	localtime_s(&t, &tb.time);

	printf("현재 날짜 및 시간 : %4d.%d.%d %d:%d:%d .%d\n",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec, tb.millitm);
}