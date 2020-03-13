#include <stdio.h>
#include <string.h>

#define TOKEN " "

void main(void)
{
	char string[100];
	char* token;
	char* context;

	puts("문자열을 입력한 후 Enter키를 치세요!");
	gets_s(string, 100);

	token = strtok_s(string, TOKEN, &context);
	while (token != NULL)
	{
		puts(token);
	
		token = strtok_s(NULL, TOKEN, &context);
	}

	puts("문자열을 입력한 후 Enter키를 치세요!");
	gets_s(string, 100);
	
	token = strtok_s(string, TOKEN, &context);
	while (token != NULL)
	{
		puts(token);

		token = strtok_s(context, TOKEN, &context);
	}
}