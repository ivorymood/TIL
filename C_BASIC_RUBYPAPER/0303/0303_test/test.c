#include <stdio.h>

int main()
{
	printf("%s \a", "AAAAA");
	printf("%s \b", "BBBBB");
	printf("%s \f", "CCCCC");
	printf("%s \n", "DDDDD");
	printf("%s \r", "FFFFF");
	printf("%s \t", "GGGGG");
	printf("%s \v", "HHHHH");

	return 0;
}