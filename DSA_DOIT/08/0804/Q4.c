/* 문자열 길이를 구하는 프로그램 */
#include <stdio.h>

/*--- 문자열 s의 길이를 구하는 함수(버전 1) ---*/
size_t str_len_1(const char* s)
{
	size_t len = 0;

	while (s[len])
	{
		len++;
	}

	return len;
}

/*--- 문자열 s의 길이를 구하는 함수(버전 2) ---*/
size_t str_len_2(const char* s)
{
	size_t len = 0;

	while (*s++)
	{
		len++;
	}

	return len;
}

/*--- 문자열 s의 길이를 구하는 함수(버전 3) ---*/
size_t str_len_3(const char* s)
{
	const char* p = s;

	while (*s)
	{
		s++;
	}

	return s - p;
}

int main(void)
{
	char str[256];

	printf("문자열 : ");
	scanf_s("%s", str, 256);

	printf("이 문자열의 길이는 %d입니다.\n", str_len_1(str));
	printf("이 문자열의 길이는 %d입니다.\n", str_len_2(str));
	printf("이 문자열의 길이는 %d입니다.\n", str_len_3(str));

	return 0;
}