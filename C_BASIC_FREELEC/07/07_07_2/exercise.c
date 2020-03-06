#include <stdio.h>

//�Ǻ���ġ n��° ��� ���ϱ�
// 0 1 ...

//������ �Է��� �ּ���?
//�Ǻ���ġ �������� d��° ��Ҵ� 5�Դϴ�. 

int fibonacci_recursive(int);

int main()
{
	int input = 0;
	int num = 0;

	printf("������ �Է��� �ּ���?");
	scanf_s("%d", &input);

	num = fibonacci_recursive(input);

	printf("�Ǻ���ġ �������� %d��° ��Ҵ� %d�Դϴ�. ", input, num);

	return 0;
}

int fibonacci_recursive(int n)
{
	int sum = 0;

	if (n <= 2)
	{
		return n - 1;
	}

	sum = fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);

	return sum;
}