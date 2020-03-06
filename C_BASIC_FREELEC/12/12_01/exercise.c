#include <stdio.h>

int check_max_min(int, int, int*, int*);

int main()
{
	int value1 = 100, value2 = 200;
	int result_max = 0, result_min = 0;
	int result = 0;

	result = check_max_min(value1, value2, &result_max, &result_min);

	if (0 == result)
	{
		printf("�ִ� : %d, �ּڰ� %d\n", result_max, result_min);
	}
	else 
	{
		printf("�����߽��ϴ�\n");
	}

	return 0;
}

int check_max_min(int value1, int value2, int* pmax_value, int* pmin_value)
	//�Ű����� 2�� ���� -> �����϶��� ū�� ������ ��ȯ
	// ������ 0��ȯ �ƴϸ� 1��ȯ
	// �ΰ��� ���� ���̸� ���� 2��ȯ
{
	int result = 0;

	if (pmax_value == NULL || pmin_value == NULL) 
	{
		return 1;
	}

	if (value1 == value2) 
	{
		return 2;
	}

	if (value1 > value2) 
	{
		*pmax_value = value1;
		*pmin_value = value2;
		result = 0;
	}
	else if (value1 < value2)
	{
		*pmax_value = value2;
		*pmin_value = value1;
		result = 0;
	}
	else 
	{
		result = 1;
	}

	return result;
}