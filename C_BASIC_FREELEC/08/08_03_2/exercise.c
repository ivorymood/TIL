#include <stdio.h>

int main()
{
	char str_name[512] = { 0 };
	
	printf("문자열은?");
	scanf_s("%s", str_name, 512);

	int offset = 0;

	for (int i = 0; i < 512; i++)
	{
		if (str_name[i] == '\0') 
		{
			offset = i;
			break;
		}

	}

	printf("문자열의 길이는 %d", offset);
}