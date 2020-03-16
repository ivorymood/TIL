#include <stdio.h>

#define IN 1
#define OUT 0

void main()
{
	int c, state;

	state = OUT;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if (state == IN)
			{
				state = OUT;
				putchar('\n');
			}
		}
		else
		{
			state = IN;
			putchar(c);
		}
	}
}