#include <stdio.h>
#include <ctype.h>

void main(void)
{
	char* string = "Cat 1 Car 2 Cow 3...";
	char buffer[100] = { 0, };
	int cnt = 0;

	while (*string)
	{
		if (islower(*string))
		{
			buffer[cnt++] = *string;
		}
		string++;
	}

	puts(buffer);
}