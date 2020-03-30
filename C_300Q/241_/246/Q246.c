#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>

#define DAYSEC 86400L

int main(void)
{
	time_t now;
	struct tm t1, t2;
	int n1, n2, last;

	now = time(NULL);
	t1 = *localtime(&now);
	t1.tm_mday = 1;
	t2 = t1;

	for (int i = 0; i < 12; i++) {
		t1.tm_mon = i;
		t2.tm_mon = i + 1;
		n1 = mktime(&t1);
		n2 = mktime(&t2);
		last = (n2 - n1) / DAYSEC;
		
		printf("%d년 %2d월의 마지막 날짜는 %d입니다. \n", t1.tm_year + 1900, t1.tm_mon + 1, last);
	}

	return 0;
}