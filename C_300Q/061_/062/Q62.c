#include <stdio.h>
#include <string.h>

void main(void)
{
	char string1[100];
	char string2[100];

	printf("첫번째 단어를 입력하세요 ! \n");
	gets_s(string1, 100);

	printf("두번째 단어를 입력하세요! \n");
	gets_s(string2, 100);

	strcat_s(string1, 100, string2);

	puts(string1);
}