#include <stdio.h>
#include <time.h>

void main(void)
{
	time_t now;
	struct tm t;
	char buff[100];

	now = time(NULL);
	localtime_s(&t, &now);
	strftime(buff, sizeof(buff), "%Y - %m - %d  %I:%M:%S %p", &t);

	puts(buff);
}