#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>

int main(void)
{
	FILE* fp;
	char buff[200];
	time_t now;
	struct tm t;

	fp = fopen("d:\\file.txt", "w+");

	if (fp == NULL)
	{
		perror("파일쓰기 개방 에러");
		_fcloseall();
		return 1;
	}

	now = time(NULL);
	t = *localtime(&now);
	sprintf(buff, "%d/%d/%d %d:%d:%d",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec);

	fputs(buff, fp);
	_fcloseall();

	return 0;
}