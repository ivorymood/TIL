#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>

int main(void)
{
	// ��������: å���� nChristmas�� int�� ����Ǿ� ����. 
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

	printf("������ ��¥�� %s \n", ctime(&now));
	printf("ũ�������� : %d���� %d�� %d�ð� %d�� %d�� ���ҽ��ϴ�. \n"
		, christmas.tm_mon, christmas.tm_mday, christmas.tm_hour
		, christmas.tm_min, christmas.tm_sec);

	return 0;
}