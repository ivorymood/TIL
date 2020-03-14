/* strstr 함수를 사용한 프로그램 */
#include <stdio.h>
#include <string.h>

char* str_rstr(const char* s1, const char* s2)
{
	if (strlen(s2) == 0)
	{
		return (char*)s1;
	}

	int s1_len = strlen(s1);
	int s2_len = strlen(s2);
	int pt = s1_len - s2_len;
	int pp;

	while (pt >= 0)
	{
		pp = 0;
		while (s1[pt] == s2[pp])
		{
			if (pp == s2_len - 1)
			{
				return &s1[pt - pp];
			}
			pp++;
			pt++;
		}
		pt = pt - pp - 1;
	}
	return NULL;
}

int main(void)
{
	char s1[256], s2[256];
	char* p;

	puts("strstr 함수");
	printf("텍스트 : ");
	scanf_s("%s", s1, 256);
	printf("패턴 : ");
	scanf_s("%s", s2, 256);

	p = str_rstr(s1, s2); 		/* 문자열 s1에서 문자열 s2를 검색 */

	if (p == NULL)
		printf("텍스트에 패턴이 없습니다.\n");
	else {
		int ofs = p - s1;
		printf("\n%s\n", s1);
		printf("%*s|\n", ofs, "");
		printf("%*s%s\n", ofs, "", s2);
	}

	return 0;
}