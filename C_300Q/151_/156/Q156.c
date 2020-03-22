#include <stdio.h>

void main(void)
{
	int i;
	char buffer[500];
	char* path;

	for (i = 0; i < 10; i++)
	{
		tmpnam_s(buffer, sizeof(buffer));
		puts(buffer);
	}

	for (i = 0; i < 10; i++)
	{
		path = _tempnam("", "test");
		puts(path);
	}
}