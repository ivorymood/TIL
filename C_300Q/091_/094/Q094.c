#include <stdio.h>
#include <ctype.h>

void main(void)
{
	char* string = "Cat 1 Car 2 Cow 3...\t\n";
	char buffer[100] = { 0, };
	int cnt = 0;

	while (*string)
	{
		if (isspace(*string))
		{
			buffer[cnt++] = *string;
		}
		string++;
	}

	printf("공백, 탭, 그리고 개행문자의 수는 %d입니다. ", cnt);
}