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

	// x�� �� �涧
	if (*x)
	{
		tmp = x;
		while (*x)
		{
			*y++ = *x++;
		}
		*tmp = *y = '\0';
	}
	// y�� �� �涧
	else if (*y)
	{
		tmp = y;
		while (*y)
		{
			*x++ = *y++;
		}
		*tmp = *x = '\0';
	}
	// ���̰� ������
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

	printf("������ s1�� \"%s\"�� ����ŵ�ϴ�. \n", s1);
	printf("������ s1�� \"%s\"�� ����ŵ�ϴ�. \n", s2);

	swap_str(s1, s2);

	puts("\n ������ s1�� s2�� ���� ���� ��ȯ�߽��ϴ�. \n");

	printf("������ s1�� \"%s\"�� ����ŵ�ϴ�. \n", s1);
	printf("������ s1�� \"%s\"�� ����ŵ�ϴ�. \n", s2);

	return 0;
}