#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>
#include <string.h>

int main(void)
{
	time_t now;
	struct tm t;
	char buff[100], AMPM[10];

	now = time(NULL);
	localtime_s(&t, &now);

	strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", &t);
	strftime(AMPM, sizeof(AMPM), "%p", &t);

	// ���� ���� ����
	if (!strcmp(AMPM, "����"))
	{
		strcpy(AMPM, "AM");
	}
	else if (!strcmp(AMPM, "����"))
	{
		strcpy(AMPM, "PM");
	}

	strcat(buff, AMPM);

	puts(buff);

	return 0;
}