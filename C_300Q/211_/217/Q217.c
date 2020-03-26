#include <stdio.h>
#include <string.h>

int main(void)
{
	char string[] = "(a12), (b34), (c56)";
	char* token;
	char* next_token;

	token = strtok_s(string, "(123456), ", &next_token);

	while (token)
	{
		puts(token);
		token = strtok_s(NULL, "(123456), ", &next_token);
	}

	return 0;
}