#include <stdio.h>

int main(void)
{
	int x, y;
	puts("�� ������ �ִ������� ���մϴ�.");
	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &x);
	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &y);

	while (y > 0)
	{
		int temp = y;
		y = x % y;
		x = temp;
	}

	printf("�ִ������� %d�Դϴ�.\n", x);

	return 0;
}