#include <stdio.h>

void main()
{
	int c;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			putchar(c);
			while (c == ' ')
			{
				c = getchar();
			}
		}
		putchar(c);
	}
}