#include <stdio.h>

int main()
{
	char szName[32] = { 0 };
	
	printf("�̸� �Է�");
	gets_s(szName, sizeof(szName));

	printf("����� �̸��� ");
	puts(szName);
	puts("�Դϴ�.");
	return 0;
}