#include <stdio.h>
#include <string.h>

#define FIND_CHAR 'h'

void main(void)
{
	char string[100];
	char* ret;

	puts("영단어를 입력한 후 Enter키를 치세요");
	puts("문자열 중에 'h'가 포함되어 있으면, 프로그램이 종료됩니다.");

	do 
	{
		gets_s(string, 100);

		ret = strchr(string, FIND_CHAR);

		if (ret == NULL)
		{
			puts("문자열 중에 'h'가 없습니다. ");
		}
		else
		{
			printf("%d 위치에서 'h'문자를 찾았습니다. ", ret - string);
			break;
		}

	} while (1);
}