#include <stdio.h>

void swap_values(int*, int*);

int main()
{
	int first_num = 100;
	int second_num = 200;

	printf("%d, %d \n", first_num, second_num);

	swap_values(&first_num, &second_num);

	printf("%d, %d \n", first_num, second_num);

	return 0;
}

void swap_values(int* pnum_first, int* pnum_second)
{
	int temp = 0;

	temp = *pnum_first;
	*pnum_first = *pnum_second;
	*pnum_second = temp;
}