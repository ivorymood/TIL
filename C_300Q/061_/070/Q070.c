#include <stdio.h>
#include <string.h>

void main(void)
{
	char string[100];

	puts("���ڿ��� �Է��� �� EnterŰ�� ġ����!");
	puts("�ƹ��͵� �Է����� ������ ���α׷��� ����˴ϴ� ! \n");

	do
	{
		gets_s(string, 100);

		if (strlen(string) == 0)
		{
			break;
		}

		_strset_s(string, 100, string[0]);
		puts(string);

	} while (1);
	
}