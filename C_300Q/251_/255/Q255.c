#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t now;
	struct tm t;

	now = time(NULL);
	t = *localtime(&now);

	printf("올해의 경과일 수 : %d\n", t.tm_yday);

	return 0;
}