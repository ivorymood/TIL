#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>

int main(void)
{
	struct tm christmas = { 0, 0, 0, 25, 12 - 1, 2020 - 1900 };
	char* wday[] = {"��", "��", "ȭ", "��", "��", "��", "��"};
	char buff[100];

	mktime(&christmas);

	strftime(buff, sizeof buff, "2020�� 12�� 25���� %A�Դϴ�.", &christmas);

	puts(buff);
	printf("2020�� 12�� 25���� %s���� �Դϴ�.\n", wday[christmas.tm_wday]);

	return 0;
}