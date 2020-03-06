#include <stdio.h>
#include <string.h>

int main()
{
	char cArray1[1024] = { 0 };
	char cArray2[1024] = { 0 };
	char* pFind = NULL;
	int count = 0;

	printf("첫 번째 문자열은?");
	scanf_s("%s", cArray1, 100);
	printf("두 번째 문자열은?");
	scanf_s("%s", cArray2, 100);


	pFind = strstr(cArray1, cArray2);
	while (pFind != NULL)
	{
		count++;
		pFind = strstr(pFind + strlen(cArray2), cArray2);
	}

	printf("문자열 \"%s\"에 문자열 \"%s\"은 %d번 있습니다. ", cArray1, cArray2, count);

	return 0;
}