#include <stdio.h>
#include <string.h>

void main(void)
{
	char s1[100] = "123";
	char s2[100] = "123";

	strcpy_s(&s1[4], 50, "abc");
	strcpy_s(&s2[4], 4, "efg");

	puts(s1);
	puts(s2);

	if (strcmp(s1, s2) == 0)
	{
		puts("strcmp : ������ ���� ��ġ�մϴ�. ");
	}

	if (memcmp(s1, s2, 7) == 0)
	{
		puts("memcmp : ������ ���� ��ġ�մϴ�. ");
	}
	else
	{
		puts("memcmp : ������ ���� ��ġ���� �ʽ��ϴ�. ");
	}
}