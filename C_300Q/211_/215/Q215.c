#include <stdio.h>
#include <string.h>

int main(void)
{
	char string[] = "This is a book";

	char* pos;

	pos = strstr(string, "book");

	if (pos)
	{
		printf("book을 %d번째에서 찾았습니다 \n", pos - string);
		printf("%s \n", &string[pos - string]);
	}

	return 0;
}