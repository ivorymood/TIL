#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t now;
	struct tm t;
	char buff[100];

	now = time(NULL);
	localtime_s(&t, &now);
	strftime(buff, sizeof(buff), "올해의 경과된 주 : %U 주", &t);

	puts(buff);

	return 0;
}