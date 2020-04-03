#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>

int main(void)
{
	struct _timeb tb;
	struct tm t;
	char buff[100];

	_ftime(&tb);

	t = *localtime(&tb.time);

	printf("%4d-%d-%d %d:%d:%d.%d \n",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec, tb.millitm);

	printf(ctime(&tb.time));
	printf(asctime(&t));
	putchar('\n');

	puts(_strdate(buff));
	puts(_strtime(buff));
	putchar('\n');

	strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S %p(%a)", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%#Y-%#m-%#d %#H:%#M:%#S %p(%a)", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%c", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%x %X", &t);
	puts(buff);
	putchar('\n');

	strftime(buff, sizeof(buff), "%#c", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%#x", &t);
	puts(buff);


	return 0;
}