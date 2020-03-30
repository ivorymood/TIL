#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t now;
	struct tm t, tb;

	now = time(NULL);
	t = *localtime(&now);

	tb = t;

	t.tm_mon += 100;
	t.tm_mday += 90;
	t.tm_hour += 80;

	mktime(&t);

	printf("������ ��¥�� %d/%d/%d %d:%d:%d �Դϴ�. \n"
		, tb.tm_year + 1900, tb.tm_mon + 1, tb.tm_mday
		, tb.tm_hour, tb.tm_min, tb.tm_sec);
	printf("100���� 90�� 80�ð��� ���� ��¥�� %d/%d/%d %d:%d:%d �Դϴ�. \n"
		, t.tm_year + 1900, t.tm_mon + 1, t.tm_mday
		, t.tm_hour, t.tm_min, t.tm_sec);

	tb.tm_mon -= 100;
	tb.tm_mday -= 90;
	tb.tm_hour -= 80;

	mktime(&tb);

	printf("100���� 90�� 80�ð��� �� ��¥�� %d/%d/%d %d:%d:%d �Դϴ�. \n"
		, tb.tm_year + 1900, tb.tm_mon + 1, tb.tm_mday
		, tb.tm_hour, tb.tm_min, tb.tm_sec);

	return 0;
}