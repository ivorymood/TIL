#include <stdio.h>
#include <string.h>

void main(void)
{
	char string[100];
	char* pstr;

	puts("���ڿ��� �Է��� �� EnterŰ�� ġ����!");
	puts("�ƹ� ���ڵ� �Է����� ������ ���α׷��� ����˴ϴ�!");

	do
	{
		gets_s(string, 100);

		if (strlen(string) == 0)
		{
			break;
		}

		pstr = _strdup(string);

		printf("���ڿ� string: %s \n", string);
		printf("���ڿ� pstr: %s \n", pstr);

	} while (1);
}