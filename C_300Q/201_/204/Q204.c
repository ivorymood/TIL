#include <stdio.h>

int main(void)
{
	int num;

	printf("���ڸ� �Է��ϼ��� : ");

	scanf_s("%d", &num);

	if (num % 2 == 1)
	{
		printf("%d�� Ȧ���Դϴ�. \n", num);
	}
	else
	{
		printf("%d�� ¦���Դϴ�. \n", num);
	}

	return 0;
}