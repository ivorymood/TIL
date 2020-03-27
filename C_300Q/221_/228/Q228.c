#include <stdio.h>
#include <string.h>

int main(void)
{
	char string[] = "암호는 Korea입니다";
	char* pstr;

	pstr = strstr(string, "Korea");

	if (pstr)
	{
		_strnset_s(pstr, sizeof(string) - (pstr - string), '*', 5);
	}

	puts(string);

	return 0;
}