#include <stdio.h>
#include <string.h>

char* str_rchr(const char* s, int c)
{
	int i = 0;
	char* p = NULL;
	c = (char)c;
	while (s[i])
	{
		if (s[i] == c)
		{
			p = (char*)(s + i);
		}
		i++;
	}
	return (char*)p;
}

int main(void)
{
	char str[64];
	char tmp[64];
	int  ch;
	char* idx_1;
	char* idx_2;

	printf("���ڿ���");
	scanf_s("%s", str, 64);

	printf("�˻���");
	scanf_s("%s", tmp, 64);
	ch = tmp[0];

	idx_2 = strrchr(str, ch);

	if ((idx_1 = str_rchr(str, ch)) == NULL)
		printf("���� '%c'�� ���ڿ� �ȿ� �����ϴ�.\n", ch);
	else
		printf("1: ���� '%c'�� %d��°�� �ֽ��ϴ�.\n", ch, (idx_1 - str) + 1);
		printf("2: ���� '%c'�� %d��°�� �ֽ��ϴ�.\n", ch, (idx_2 - str) + 1);

	return 0;
}