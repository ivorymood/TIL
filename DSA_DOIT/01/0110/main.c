#include <stdio.h>
void minus();
void get_digit();

int main()
{

	


	minus();
	get_digit();

	return 0;
}

void minus()
{
	int a, b = 0;
	printf("a �� b �Է� \n");
	scanf_s("%d", &a);

	while (1)
	{
		scanf_s("%d", &b);

		if (b <= a)
		{
			break;
		}
			printf("a���� ū ���� �Է��ϼ���!\n");
	}

	printf("b - a�� %d�Դϴ� \n", b - a);
}

void get_digit()
{
	int num = 0;
	int digit = 0;
	printf("���� �Է� \n");
	scanf_s("%d", &num);

	while (num > 0)
	{
		digit++;
		num /= 10;
	}

	printf("�� ���� %d�ڸ� �Դϴ�. \n", digit);

}