#include <stdio.h>
#include <stdlib.h>

int gcd_array(const int a[], int n);
int gcd_array2(const int a[], int n);
int gcd(int x, int y);

int main(void)
{
	int size;
	int* array = NULL;
	printf("요소 개수 입력 : ");
	scanf_s("%d", &size);

	array = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; ++i)
	{
		printf("array[%d] : ", i);
		scanf_s("%d", &array[i]);
	}

	printf("배열의 모든 요소의 최대공약수1 : %d\n", gcd_array(array, size));
	printf("배열의 모든 요소의 최대공약수2 : %d\n", gcd_array2(array, size));

	free(array);

	return 0;
}

int gcd_array(const int a[], int n)
{
	if (n < 1)
	{
		return -1;
	}

	int result = a[0];

	for (int i = 1; i < n; ++i)
	{
		result = gcd(a[i], result);
	}
	return result;
}

int gcd_array2(const int a[], int n)
{
	if (n == 1)
	{
		return a[0];
	}
	return gcd(a[0], gcd_array2((a + 1), n - 1));
}

int gcd(int x, int y)
{
	if (y == 0)
	{
		return x;
	}
	return gcd(y, x % y);
}