#include <stdio.h>

int bf_match(const char txt[], const char pat[])
{
	int pt = 0; // txt커서
	int pp = 0; // pat커서
	int count = 0;
	int right = 0;

	while (txt[pt] != '\0' && pat[pp] != '\0')
	{
		printf("%3d %s\n", count, txt);

		if (txt[pt] == pat[pp])
		{
			printf("%*c\n", (pp + count + 5), '+');
			pt++;
			pp++;
			right = 1;
		}
		else
		{
			printf("%*c\n", (pp + count + 5), '|');
			pt = pt - pp + 1;
			pp = 0;
			right = 0;
			count++;
		}
		
		printf("%*s%s\n", (right) ? (count + 4) : (count + 3), "", pat);
		
	}

	printf("비교를 %d회 시도합니다.\n", count);

	if (pat[pp] == '\0')
	{
		return pt - pp;
	}
	return -1;
}

int main()
{
	int idx;
	char s1[256];
	char s2[256];
	puts("브루트-포스법");
	printf("텍스트 : ");
	scanf_s("%s", s1, 256);
	printf("패턴 : ");
	scanf_s("%s", s2, 256);

	idx = bf_match(s1, s2);

	if (idx == -1)
	{
		puts("텍스트에 패턴이 없습니다 ");
	}
	else
	{
		printf("%d번째 문자부터 match합니다. \n", idx + 1);
	}

	return 0;
}