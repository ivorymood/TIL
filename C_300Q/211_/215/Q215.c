#include <stdio.h>
#include <string.h>

int main(void)
{
	char string[] = "This is a book";

	char* pos;

	pos = strstr(string, "book");

	if (pos)
	{
		printf("book�� %d��°���� ã�ҽ��ϴ� \n", pos - string);
		printf("%s \n", &string[pos - string]);
	}

	return 0;
}