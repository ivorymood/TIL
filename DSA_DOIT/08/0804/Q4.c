/* ���ڿ� ���̸� ���ϴ� ���α׷� */
#include <stdio.h>

/*--- ���ڿ� s�� ���̸� ���ϴ� �Լ�(���� 1) ---*/
size_t str_len_1(const char* s)
{
	size_t len = 0;

	while (s[len])
	{
		len++;
	}

	return len;
}

/*--- ���ڿ� s�� ���̸� ���ϴ� �Լ�(���� 2) ---*/
size_t str_len_2(const char* s)
{
	size_t len = 0;

	while (*s++)
	{
		len++;
	}

	return len;
}

/*--- ���ڿ� s�� ���̸� ���ϴ� �Լ�(���� 3) ---*/
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

	printf("���ڿ� : ");
	scanf_s("%s", str, 256);

	printf("�� ���ڿ��� ���̴� %d�Դϴ�.\n", str_len_1(str));
	printf("�� ���ڿ��� ���̴� %d�Դϴ�.\n", str_len_2(str));
	printf("�� ���ڿ��� ���̴� %d�Դϴ�.\n", str_len_3(str));

	return 0;
}