#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main(void)
{
	char buff[] = "암호는 Korea입니다";
	char* dup;

	dup = _strdup(buff);

	if (dup)
	{
		strcpy_s(buff, sizeof(buff), "다른 문자열");
		puts(buff);
		puts(dup);
		free(dup);
	}

	return 0;
}