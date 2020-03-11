#include <stdio.h>
#include <stdlib.h>

void insertion(int a[], int n)
{
	int i, j;
	for (i = 2; i <= n; ++i)
	{
		a[0] = a[i];
		for (j = i; a[j - 1] > a[0]; --j)
		{
			a[j] = a[j - 1];
		}
		a[j] = a[0];
	}
}

int main(void)
{
	int nx;
	int* x;
	puts("단순 삽입 정렬 (보초법)");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = calloc(nx + 1, sizeof(int));

	for (int i = 1; i < nx + 1; ++i)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	insertion(x, nx);

	puts("오름차순으로 정렬했습니다. ");
	for (int i = 1; i < nx + 1; ++i)
	{
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);

	return 0;
}