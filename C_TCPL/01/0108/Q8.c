#include <stdio.h>

void main()
{
	//blank tab newline
	int c, nb, nt, nl;

	nb = nt = nl = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')	++nb;
		if (c == '\t')	++nt;
		if (c == '\n')	++nl;
	}
	printf("blank : %d\n", nb);
	printf("tab : %d\n", nt);
	printf("new line : %d\n", nl);

}