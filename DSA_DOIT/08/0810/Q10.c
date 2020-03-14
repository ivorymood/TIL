#include <stdio.h>
#include <string.h>

int bf_matchr(const char txt[], const char pat[])
{
	int pt = strlen(txt) - 1; // txt커서
	int pp = strlen(pat) - 1; // pat커서

	while (pt >=0 && pp >= 0)
	{
		if (txt[pt] == pat[pp])
		{
			pt--;
			pp--;
		}
		else
		{
			pt = pt - pp + strlen(pat) - 2;
			pp = strlen(pat) - 1;;
		}
	}

	if (pp < 0)
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

	idx = bf_matchr(s1, s2);

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