#include <stdio.h>
#include <string.h>

int main(void)
{
	char* string = "it`s good";
	char* find = "abcdefghijklmnopqrstuvwxyz";
	int nIndex;

	nIndex = strspn(string, find);
	printf("%d ��ġ���� ���ĺ��� �ƴ� ù ���ڸ� ã�ҽ��ϴ�. \n", nIndex);

	return 0;
}