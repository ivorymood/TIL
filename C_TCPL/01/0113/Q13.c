#include <stdio.h>

void aaa(char s[], char t[])
{
	int i, j;
	i = j = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	while ((s[i++] = t[j++]) != '\0')
	{
		;
	}

	printf("s[%d] : (%c)  t[%d] : (%c)\n", i-1, s[i-1], j-1, t[j-1]);
	printf("s[%d] : (%c)  t[%d] : (%c)\n", i, s[i], j, t[j]);
}

void main()
{
	char s[10] = "abc";
	char t[10] = "cdef";

	aaa(s, t);


}

