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

		_strrev(string);
		puts(string);

	} while (1);
}