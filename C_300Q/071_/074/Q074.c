#include <stdio.h>
#include <string.h>

void main(void)
{
	char string[100];

	puts("문자열을 입력한 후 Enter키를 치세요!");
	puts("아무 문자도 입력하지 않으면 프로그램은 종료됩니다!");

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