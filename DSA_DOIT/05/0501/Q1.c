#include <stdio.h>

int main(void)
{
	int x = 0;
	int result = 1;
	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &x);

	for (int i = 1; i <= x; ++i)
	{
		result *= i;
	}

	printf("%d�� �������� ���� %d �Դϴ�", x, result);

	return 0;
}