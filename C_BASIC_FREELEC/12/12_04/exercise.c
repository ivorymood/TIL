#include <stdio.h>

void print_array_reverse(const double* pdouble_array, const int size) {

	if (pdouble_array == NULL || size < 0) 
	{
		printf("¿À·ù!");
	}

	for (int i = 0; i < size; i++)
	{
		printf("[%d] %.2lf \n", i, *(pdouble_array + size - i - 1));
	}
}

int main()
{
	double double_array[] = { 10.0, 20.1, 30.2, 40.3 };
	int size = sizeof(double_array) / sizeof(double);

	print_array_reverse(double_array, size);

	return 0;
}