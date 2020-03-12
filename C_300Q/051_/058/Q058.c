#include <stdio.h>

#define KOREA "���ѹα�"

char* My_strcpy(char* dest, const char* src);

void main(void)
{
	char string[100];

	My_strcpy(string, KOREA);

	puts(string);
}

char* My_strcpy(char* dest, const char* src)
{
	if (dest == (int)NULL || src == (int)NULL)
	{
		if (*dest != (int)NULL) *dest = (int)NULL;
		return NULL;
	}

	do
	{
		*dest++ = *src++; // ������ NULL���� ����
	} 
	while (*(src - 1) != (int)NULL);

	return dest;
}