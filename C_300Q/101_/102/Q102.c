#include <stdio.h>
#include <string.h>

char s1[20] = "12345678909";
char s2[20] = "12345678909";

void main(void)
{
	puts(s1);
	memcpy(s1 + 4, s1 + 2, 5);
	puts(s1);

	puts(s2);
	memmove(s2 + 4, s2 + 2, 5);
	puts(s2);
}