#include <stdio.h>

int main()
{
	char szName[32] = { 0 };
	
	printf("이름 입력");
	gets_s(szName, sizeof(szName));

	printf("당신의 이름은 ");
	puts(szName);
	puts("입니다.");
	return 0;
}