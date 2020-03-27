#include <stdio.h>
#include <string.h>

int main(void)
{
	char* string = "abc 1  2 gd2";
	char* find = "0123456789";
	int nIndex;

	nIndex = strcspn(string, find);
	printf("%d 위치에서 일치되는 첫 숫자를 찾았습니다. \n", nIndex);

	return 0;
}