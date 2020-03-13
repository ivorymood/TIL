
/* 문자열에서 문자 검색하는 프로그램 */
#include <stdio.h>
#include <string.h>

/*--- 문자열 s에서 문자 c를 검색하는 함수 ---*/
char* str_chr(const char* s, int c)
{
	int i = 0;
	c = (char)c;
	while (s[i] != c) 
	{
		if (s[i] == '\0')
		{
			return NULL;	/* 검색 실패 */
		}
		i++;
	}
	return (char*)(s + i);			/* 검색 성공 */
}

int main(void)
{
	char str[64];	/* 이 문자열에서 검색*/
	char tmp[64];
	int ch;			/* 검색할 문자 */
	char* pidx;
	char* pidx_2;

	printf("문자열 : ");
	scanf_s("%s", str, 64);

	printf("검색할 문자 : ");
	scanf_s("%s", tmp, 64);		/* 먼저 문자열로 검색할 문자를 읽어 들입니다. */
	ch = tmp[0];				/* 첫 번째 문자를 검색할 문자로 지정합니다. */

	pidx_2 = strchr(str, ch);
	
	if ((pidx = str_chr(str, ch)) == NULL)		/* 처음 나오는 문자를 검색합니다. */
	{
		printf("문자 '%c'는 문자열에 없습니다.\n", ch);
	}
	else
	{
		printf("1: 문자 '%c'는(은) %d 번째에 있습니다.\n", ch, (pidx - str) + 1);
		printf("2: 문자 '%c'는(은) %d 번째에 있습니다.\n", ch, (pidx_2 - str) + 1);
	}

	return 0;
}