#include <stdio.h>
#include <string.h>

int main(void)
{
	char string[] = "��ȣ�� Korea�Դϴ�";
	char* pstr;

	pstr = strstr(string, "Korea");

	if (pstr)
	{
		_strnset_s(pstr, sizeof(string) - (pstr - string), '*', 5);
	}

	puts(string);

	return 0;
}