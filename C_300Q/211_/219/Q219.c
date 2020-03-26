#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char* string = "temperature: 200";
	char buff[20] = { 0 , };
	int i = 0;

	while (*string)
	{
		if (isalpha(*string))
		{
			buff[i++] = *string;
		}
		string++;
	}
	puts(buff);

	return 0;
}