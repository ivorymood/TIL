#include <stdio.h>

int count_a(char* str);

void main(void)
{
	char string[100];
	char* ret;

	ret = gets_s(string, sizeof(string));

	if (ret != NULL)
	{
		printf("문자 'a' 의 갯수는 %d개 입니다.", count_a(ret));
	}
}

int count_a(char* str)
{
	int cnt = 0;

	while (*str != (int)NULL)
	{
		if (*str++ == 'a') cnt++;
	}

	return cnt;
}