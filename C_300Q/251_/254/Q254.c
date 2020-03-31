#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>

int main(void)
{
	struct tm t1, t2, t3;
	time_t  n1, n2, n3;

	t1.tm_year = 2020 - 1900;
	t1.tm_mon = 6 - 1;
	t1.tm_mday = 23;
	t1.tm_hour = 1;
	t1.tm_min = 12;
	t1.tm_sec = 50;

	t2.tm_year = 2020 - 1900;
	t2.tm_mon = 8 - 1;
	t2.tm_mday = 19;
	t2.tm_hour = 3;
	t2.tm_min = 35;
	t2.tm_sec = 22;

	n1 = mktime(&t1);
	n2 = mktime(&t2);

	n3 = n2 - n1;
	t3 = *gmtime(&n3);
	t3.tm_year -= 70;

	printf("시간 1: %4d-%02d-%02d %02d:%02d:%02d \n"
		, t1.tm_year + 1900, t1.tm_mon + 1, t1.tm_mday
		, t1.tm_hour, t1.tm_min, t1.tm_sec);

	printf("시간 2: %4d-%02d-%02d %02d:%02d:%02d \n"
		, t2.tm_year + 1900, t2.tm_mon + 1, t2.tm_mday
		, t2.tm_hour, t2.tm_min, t2.tm_sec);

	printf("날짜차이: %4d-%02d-%02d %02d:%02d:%02d \n"
		, t3.tm_year, t3.tm_mon, t3.tm_mday
		, t3.tm_hour, t3.tm_min, t3.tm_sec);

	return 0;
}