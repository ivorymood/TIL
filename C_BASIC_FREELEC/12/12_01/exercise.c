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
		printf("최댓값 : %d, 최솟값 %d\n", result_max, result_min);
	}
	else 
	{
		printf("실패했습니다\n");
	}

	return 0;
}

int check_max_min(int value1, int value2, int* pmax_value, int* pmin_value)
	//매개변수 2개 전달 -> 성공일때만 큰값 작은값 반환
	// 정상동작 0반환 아니면 1반환
	// 두개가 같은 값이면 실패 2반환
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