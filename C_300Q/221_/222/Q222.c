#include <stdio.h>
#include <string.h>

int main(void)
{
	char* string = "abc 1  2 gd2";
	char* find = "0123456789";
	int nIndex;

	nIndex = strcspn(string, find);
	printf("%d ��ġ���� ��ġ�Ǵ� ù ���ڸ� ã�ҽ��ϴ�. \n", nIndex);

	return 0;
}