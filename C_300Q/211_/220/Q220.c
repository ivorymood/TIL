#include <stdio.h>
#include <ctype.h>

int main(void)
{
	unsigned char* string = "���ѹα� Korea123";
	unsigned char buff[20] = { 0, };
	int i = 0;

	while (*string)
	{
		if (*string > 127)
		{
			buff[i++] = *string;
		}
		string++;
	}
	puts(buff);

	return 0;
}