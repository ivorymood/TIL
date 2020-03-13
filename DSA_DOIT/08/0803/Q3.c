#include <stdio.h>

void swap_str(char* x, char* y)
{
	while (*x && *y)
	{
		char t = *x;
		*x++ = *y;
		*y++ = t;
	}

	char* tmp;

	// x가 더 길때
	if (*x)
	{
		tmp = x;
		while (*x)
		{
			*y++ = *x++;
		}
		*tmp = *y = '\0';
	}
	// y가 더 길때
	else if (*y)
	{
		tmp = y;
		while (*y)
		{
			*x++ = *y++;
		}
		*tmp = *x = '\0';
	}
	// 길이가 같으면
	else
	{
		printf("check\n");
		*x = *y = '\0';
	}
}

int main(void)
{
	char s1[100] = "ABCD";
	char s2[100] = "EFGH";

	printf("포인터 s1은 \"%s\"를 가리킵니다. \n", s1);
	printf("포인터 s1은 \"%s\"를 가리킵니다. \n", s2);

	swap_str(s1, s2);

	puts("\n 포인터 s1과 s2의 값을 서로 교환했습니다. \n");

	printf("포인터 s1은 \"%s\"를 가리킵니다. \n", s1);
	printf("포인터 s1은 \"%s\"를 가리킵니다. \n", s2);

	return 0;
}