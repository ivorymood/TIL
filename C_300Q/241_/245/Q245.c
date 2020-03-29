#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>

#define DAYSEC (24 * 60 * 60)

int main(void)
{
	time_t n1, n2;
	struct tm t1, t2;
	double elapsed;

	t1.tm_year = 103;
	t1.tm_mon = 10 - 1;
	t1.tm_mday = 15;
	t1.tm_hour = 0;
	t1.tm_min = 0;
	t1.tm_sec = 0;

	n1 = time(NULL);
	t2 = *localtime(&n1);

	n1 = mktime(&t1);
	n2 = mktime(&t2);

	// 현재 - 태어난 시점
	n2 = n2 - n1;
	elapsed = (double)(n2 / DAYSEC);

	printf("가나다는 태어난지 %.f일째 입니다. \n", elapsed);

	return 0;
}