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
	
	// ���� n���� ��� ���Ҵٸ�
	if (!n) return 0;
	// s1�� �� ��ٸ�
	if (*s1) return 1;
	// s2�� �� ��ٸ�
	return -1;
}

int main(void)
{
	char st[128];

	puts("\"STRING\"�� ó�� �� ���ڿ� ���մϴ�.");
	puts("\"XXXX\"�̸� �����մϴ�.");

	while (1) {
		printf("���ڿ���");
		scanf_s("%s", st, 128);

		if (str_ncmp("XXXX", st, 3) == 0)
		{
			break;
		}
		printf("str_ncmp(\"STRING\", st, 3) = %d\n", str_ncmp("STRING", st, 3));
	}

	return 0;
}