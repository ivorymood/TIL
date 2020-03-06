#include <stdio.h>

typedef struct
{
	int y;
	int m;
	int d;
} Date;

Date DateOf(int y, int m, int d);
Date After(Date x, int n);
Date Before(Date x, int n);
int isleap(int year);
int dayofyear(int y, int m, int d);

int mdays[][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


int main(void)
{
	int year, month, day;
	int n;
	Date date = { 0 };
	Date date_2 = { 0 };

	printf("�� : ");
	scanf_s("%d", &year);
	printf("�� : ");
	scanf_s("%d", &month);
	printf("�� : ");
	scanf_s("%d", &day);
	printf("n�� : ");
	scanf_s("%d", &n);

	date = DateOf(year, month, day);
	date_2 = DateOf(year, month, day);
	printf("%d�� %d�� %d��\n", date.y, date.m, date.d);

	date = After(date, n);
	printf("%d�� %d�� %d��\n", date.y, date.m, date.d);

	date_2 = Before(date_2, n);
	printf("%d�� %d�� %d��\n", date_2.y, date_2.m, date_2.d);

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

Date DateOf(int y, int m, int d)
{
	Date date = { 0 };

	date.y = y;
	date.m = m;
	date.d = d;

	return date;
}

Date After(Date date, int n)
{
	int days = date.d + n;
	int month = date.m - 1;
	int leap = isleap(date.y);
	int gap_y = 0;

	while (days - mdays[leap][month] > 0)
	{
		days -= mdays[leap][month];
		month++;

		if (month > 11)
		{
			gap_y++;
			month %= 11;
		}
		leap = isleap(date.y + gap_y);
	}

	date.y += gap_y;
	date.m = month + 1;
	date.d = days;

	return date;
}

Date Before(Date date, int n)
{
	int days = date.d - n;
	int month = date.m - 1;
	int leap = isleap(date.y);
	int gap_y = 0;

	if (days < 0)
	{
		month -= 1;

		while (1)
		{
			days += mdays[leap][month];
			month--;

			if (month < 0)
			{
				gap_y++;
				month = 11;
			}
			leap = isleap(date.y - gap_y);

			if (days >= 0)
			{
				break;
			}
		}
		month += 1;
	}

	date.y -= gap_y;
	date.m = month + 1;
	date.d = days;

	return date;
}