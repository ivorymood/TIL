#include <stdio.h>

int main()
{
	char szName[32] = { 0 };
	int nAge = 0;

	printf("���� �Է� ����: ");
	scanf_s("%d%*c", &nAge);

	printf("�̸� �Է� ����: ");

	//fflush(stdin);

	gets_s(szName, sizeof(szName));
	
	printf("%d, %s\n", nAge, szName);

	return 0;
}