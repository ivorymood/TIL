#include <stdio.h>

int isleap(int year);
int dayofyear(int y, int m, int d);

int mdays[][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(void)
{
	int year, month, day;
	int retry;

	do
	{
		printf("년 : "); scanf_s("%d", &year);
		printf("월 : "); scanf_s("%d", &month);
		printf("일 : "); scanf_s("%d", &day);
		
		printf("%d년의 %d일째 입니다\n", year, dayofyear(year, month, day));

		printf("다시 할까요? (1 - 예 / 0 - 아니오 : ");
		scanf_s("%d", &retry);

	} while (retry == 1);

	return 0;
}

int isleap(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int dayofyear(int y, int m, int d)
{
	int leaped = isleap(y);
	m = m - 2;

	while (m >= 0)
	{
		d += mdays[leaped][m];
		m--;
	}
	return d;
}