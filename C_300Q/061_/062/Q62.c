#include <stdio.h>
#include <string.h>

void main(void)
{
	char string1[100];
	char string2[100];

	printf("ù��° �ܾ �Է��ϼ��� ! \n");
	gets_s(string1, 100);

	printf("�ι�° �ܾ �Է��ϼ���! \n");
	gets_s(string2, 100);

	strcat_s(string1, 100, string2);

	puts(string1);
}