#include <stdio.h>

int main()
{
	//�����ͺ���, ������ ������ �̿��ؼ�

	int my_int_array[] = { 11, 22, 33, 44, 55, 66, 77 };
	int* pint_value = &my_int_array[0];

	int max = *pint_value;
	int min = *pint_value;
	int total = 0;
	int length = sizeof(my_int_array) / sizeof(int);

	for (int i = 0; i < length; i++)
	{
		total += *(pint_value + i);
		max = (max < *(pint_value + i)) ? *(pint_value + i) : max;
		min = (min > *(pint_value + i)) ? *(pint_value + i) : min;
	}

	printf("�ִ� : %d \t�ּڰ� : %d \t��հ� : %f \n", max, min, (double)total / length);

	return 0;
}