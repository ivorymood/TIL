#include <stdio.h>

int count_a(char* str);

void main(void)
{
	char string[100];
	char* ret;

	ret = gets_s(string, sizeof(string));

	if (ret != NULL)
	{
		printf("���� 'a' �� ������ %d�� �Դϴ�.", count_a(ret));
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