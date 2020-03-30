#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>

int main(void)
{
	// 오류수정: 책에는 nChristmas가 int로 선언되어 있음. 
	time_t now, nChristmas;
	struct tm t, christmas = { 0, 0, 0, 25, 12, 2020 }; 
	int n1, n2;

	now = time(NULL);
	t = *localtime(&now);

	christmas.tm_year -= 1900;
	christmas.tm_mon -= 1;

	n1 = mktime(&t);
	n2 = mktime(&christmas);

	nChristmas = n2 - n1;
	christmas = *localtime(&nChristmas);

	printf("오늘의 날짜는 %s \n", ctime(&now));
	printf("크리스마스 : %d개월 %d일 %d시간 %d분 %d초 남았습니다. \n"
		, christmas.tm_mon, christmas.tm_mday, christmas.tm_hour
		, christmas.tm_min, christmas.tm_sec);

	return 0;
}