#include <stdio.h>
#include <string.h>

int str_ncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (unsigned char)*s1 - (unsigned char)*s2;
		}
		s1++;
		s2++;
		n--;
	}
	
	// 길이 n까지 모두 같았다면
	if (!n) return 0;
	// s1이 더 길다면
	if (*s1) return 1;
	// s2가 더 길다면
	return -1;
}

int main(void)
{
	char st[128];

	puts("\"STRING\"의 처음 세 문자와 비교합니다.");
	puts("\"XXXX\"이면 종료합니다.");

	while (1) {
		printf("문자열：");
		scanf_s("%s", st, 128);

		if (str_ncmp("XXXX", st, 3) == 0)
		{
			break;
		}
		printf("str_ncmp(\"STRING\", st, 3) = %d\n", str_ncmp("STRING", st, 3));
	}

	return 0;
}
