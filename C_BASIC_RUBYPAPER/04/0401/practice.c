#include <stdio.h>

int main(void)
{
	int x = 0, y = 0;

	printf("�� ������ �Է��ϼ��� : ");
	scanf_s("%d", &x);
	scanf_s("%d", &y);

	printf("AVG : %.2f", (x + y) / 2.0);

	return 0;
}