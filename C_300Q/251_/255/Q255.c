#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t now;
	struct tm t;

	now = time(NULL);
	t = *localtime(&now);

	printf("������ ����� �� : %d\n", t.tm_yday);

	return 0;
}