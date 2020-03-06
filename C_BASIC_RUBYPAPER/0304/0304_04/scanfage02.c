#include <stdio.h>

int main()
{
	char szName[32] = { 0 };
	int nAge = 0;

	printf("나이 입력 ㄱㄱ: ");
	scanf_s("%d%*c", &nAge);

	printf("이름 입력 ㄱㄱ: ");

	//fflush(stdin);

	gets_s(szName, sizeof(szName));
	
	printf("%d, %s\n", nAge, szName);

	return 0;
}