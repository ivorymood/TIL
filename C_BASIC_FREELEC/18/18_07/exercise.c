#include <stdio.h>
#include <string.h>

int main()
{
	char cArray1[1024] = { 0 };
	char cArray2[1024] = { 0 };
	char* pFind = NULL;
	int count = 0;

	printf("ù ��° ���ڿ���?");
	scanf_s("%s", cArray1, 100);
	printf("�� ��° ���ڿ���?");
	scanf_s("%s", cArray2, 100);


	pFind = strstr(cArray1, cArray2);
	while (pFind != NULL)
	{
		count++;
		pFind = strstr(pFind + strlen(cArray2), cArray2);
	}

	printf("���ڿ� \"%s\"�� ���ڿ� \"%s\"�� %d�� �ֽ��ϴ�. ", cArray1, cArray2, count);

	return 0;
}