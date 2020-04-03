#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{				 //0123456789012345678
	char date[] = "2020-06-23 02:09:21";
	struct tm t= { 0, };

	t.tm_sec = atoi(&date[17]);
	date[16] = 0;
	t.tm_min = atoi(&date[14]);
	date[13] = 0;
	t.tm_hour = atoi(&date[11]);
	date[10] = 0;
	t.tm_mday = atoi(&date[8]);
	date[7] = 0;
	t.tm_mon = atoi(&date[5]) - 1;
	date[4] = 0;
	t.tm_year = atoi(&date[0]) - 1900;

	mktime(&t);

	printf("struct tm 변환 후 날짜 : %4d-%02d-%02d %02d:%02d:%02d \n"
			, t.tm_year + 1900, t.tm_mon + 1, t.tm_mday
			, t.tm_hour, t.tm_min, t.tm_sec);

	return 0;
}