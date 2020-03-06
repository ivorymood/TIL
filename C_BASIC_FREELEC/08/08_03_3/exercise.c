#include <stdio.h>

int main()
{
	char str_source[] = "복사해보세요";
	char str_dest[100] = { 0 };

	for (int i = 0; i < sizeof(str_source) / sizeof(char); i++)
	{
		str_dest[i] = str_source[i];
	}

	printf("%s, %s", str_source, str_dest);

	return 0;
}