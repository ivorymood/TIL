#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KOREA "¥Î«—πŒ±π"

void main(void)
{
	char* string1 = NULL;
	char string2[100];

	string1 = calloc(30, sizeof(char));

	strcpy_s(string1, 30, KOREA);
	puts(string1);
	strcpy_s(string2, _countof(string2), KOREA);
	puts(string2);
	strcpy_s(string2, _countof(string2), "∫Ω");
	puts(string2);

	free(string1);
}