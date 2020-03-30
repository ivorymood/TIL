#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>

#define DAYSEC 86400L

int main(void)
{
	time_t now;
	struct tm t, dday = {0, 0, 0, 8, 9, 2020}; // 2020년 9월 8일
	int n1, n2, nDday;

	now = time(NULL);
	t = *localtime(&now);

	dday.tm_year -= 1900;
	dday.tm_mon -= 1;

	t.tm_hour = 0;
	t.tm_min = 0;
	t.tm_sec = 0;

	n1 = mktime(&t);
	n2 = mktime(&dday);

	nDday = (n2 - n1) / DAYSEC;

	printf("오늘의 날짜는 %s \n", ctime(&now));
	printf("지정된 날짜 : %d일 남았습니다. (%d/%d/%d) \n"
		, nDday, dday.tm_year + 1900, dday.tm_mon + 1, dday.tm_mday);
	

	return 0;
}