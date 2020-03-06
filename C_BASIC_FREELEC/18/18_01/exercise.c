#include <stdio.h>
#include <string.h>

int main()
{
	char cArray1[10] = { 0 };
	char cArray2[10] = { 0 };
	char cArray3[] = "¾È³ç";

	for (int i = 0; i < 9; i++)
	{
		cArray1[i] = 'A';
	}

	for (int i = 0; i < 10; i++)
	{
		cArray2[i] = 'A';
	}

	printf("%s\n", cArray1);
	printf("%d\n", strlen(cArray1));
	printf("%d\n", sizeof(cArray1));
	printf("%d\n", sizeof(cArray1)/ sizeof(char));

	for (int i = 0; i < 11; i++)
	{
		printf("[%d] : %c\n", i, cArray1[i]);
	}

	printf("%s\n", cArray2);
	printf("%d\n", strlen(cArray2));
	printf("%d\n", sizeof(cArray2));
	printf("%d\n", sizeof(cArray2)/ sizeof(char));
	for (int i = 0; i < 11; i++)
	{
		printf("[%d] : %c\n", i, cArray2[i]);
	}

	printf("%s\n", cArray3);
	printf("%d\n", strlen(cArray3));
	printf("%d\n", sizeof(cArray3));
	printf("%d\n", sizeof(cArray3) / sizeof(char));
	for (int i = 0; i < 6; i++)
	{
		printf("[%d] : %c\n", i, cArray3[i]);
	}
	return 0;
}