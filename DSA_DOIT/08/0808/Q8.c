#include <stdio.h>
#include <string.h>
#include <ctype.h>

int str_cmpic(const char* s1, const char* s2)
{
	char c1, c2;

	while (*s1 && *s2)
	{
		c1 = (*s1 > 'a') ? *s1 - 32 : *s1;
		c2 = (*s2 > 'a') ? *s2 - 32 : *s2;

		if (c1 < c2)
		{
			return -1;
		}
		else if (c1 > c2)
		{
			return 1;
		}
		else
		{
			s1++;
			s2++;
		}
	}

	if (*s1)
	{
		return 1;
	}
	else if (*s2)
	{
		return -1;
	}
	return 0;
}

int str_ncmpic(const char* s1, const char* s2, size_t n)
{
	char c1, c2;

	while (n && *s1 && *s2)
	{
		c1 = (*s1 > 'a') ? *s1 - 32 : *s1;
		c2 = (*s2 > 'a') ? *s2 - 32 : *s2;

		if (c1 < c2)
		{
			return -1;
		}
		else if (c1 > c2)
		{
			return 1;
		}
		else
		{
			s1++;
			s2++;
			n--;
		}
	}

	if (n <= 0)
	{
		return 0;
	}
	else if (*s1)
	{
		return 1;
	}
	else if (*s2)
	{
		return -1;
	}
	return 0;
}

int str_cmpic_2(const char* s1, const char* s2)
{
	while (toupper(*s1) == toupper(*s2))
	{
		if (*s1 == '\0')
		{
			return 0;
		}
		s1++;
		s2++;
	}
	return (unsigned char)toupper(*s1) - (unsigned char)toupper(*s2);
}

int str_ncmpic_2(const char* s1, const char* s2, size_t n)
{
	while (n && *s1 && *s2)
	{
		if (toupper(*s1) != toupper(*s2))
		{
			return (unsigned char)toupper(*s1) - (unsigned char)toupper(*s2);
		}
		s1++;
		s2++;
		n--;
	}

	if (!n) return 0;
	if (*s1) return toupper(*s1);
	return -toupper(*s2);
}

int main(void)
{
	char st[128];

	printf("%d\n", ('a' - 'A'));

	puts("\"STRING\"의 처음 3개의 문자와 비교합니다. ");
	puts("\"XXXX\"를 입력하면 종료합니다. ");

	while (1)
	{
		printf("문자열 st : ");
		scanf_s("%s", st, 128);
	
		if (str_cmpic("XXXX", st) == 0)
		{
			break;
		}
	
		printf("str_ncmpic(\"STRING\", st, 3) = %d\n", str_ncmpic("STRING", st, 3));
		printf("str_cmpic(\"STRING\", st) = %d\n", str_cmpic("STRING", st));
	}
	return 0;
}
