#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char szBuffer[12] = { "HelloWorld" };
	char* pszData = NULL;

	pszData = (char*)malloc(sizeof(char) * 12);
	//pszData = szBuffer;
	strcpy_s(pszData, sizeof(szBuffer), szBuffer);

	puts(pszData);

	if (pszData != NULL) free(pszData);
	
	return 0;
}