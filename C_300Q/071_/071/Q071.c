#include <stdio.h>
#include <string.h>

void main(void)
{
	char string[100];

	puts("���ڿ��� �Է��� �� EnterŰ�� ġ����!");
	puts("�ƹ� ���ڵ� �Է����� ������ ���α׷��� ����˴ϴ�!");

	do
	{
		gets_s(string, 100);

		if (strlen(string) == 0)
		{
			break;
		}

		_strnset_s(string, 100, '*', 5);
		puts(string);

	} while (1);
}