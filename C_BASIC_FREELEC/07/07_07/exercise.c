#include <stdio.h>

// ������ �Է��� �ּ��� ? 5
// 1���� 5������ ������ ���� 15�Դϴ�
// int n�Է� �޾Ƽ� 1~n���� ���ϴ� ���α׷�

int sum_recursive(int);

int main()
{
	int input = 0;
	int sum = 0;

	printf("������ �Է��� �ּ��� ?");
	scanf_s("%d", &input);

	sum = sum_recursive(input);

	printf("1���� %d������ ������ ���� %d�Դϴ�",input, sum);

	return 0;
}

int sum_recursive(int n)
{
	int sum = 0;

	if (n <= 1) 
	{
		return 1;
	}

	sum += n + sum_recursive(n - 1);

	return sum;
}