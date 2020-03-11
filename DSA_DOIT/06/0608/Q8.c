#include <stdio.h>
#include <stdlib.h>

void print_array(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%3d", a[i]);
	}
	putchar('\n');
}

void print_mark(int a[], int n, int inserted, int selected)
{
	printf("%*s%s", 3 * inserted, "", (inserted != selected) ? "^-" : "  ");
	for (int i = 0; i < 3 * (selected - inserted); i++)
	{
		putchar('-');
	}
	printf("+\n\n");
}

void insertion(int a[], int n)
{
	int i, j;
	for (i = 1; i < n; ++i)
	{
		print_array(a, n);
		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; --j)
		{
			a[j] = a[j - 1];
		}
		a[j] = tmp;
		print_mark(a, n, j, i);
	}
}

int main(void)
{
	int nx;
	int* x;
	puts("단순 삽입 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (int i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	insertion(x, nx);

	puts("오름차순으로 정렬했습니다. ");
	for (int i = 0; i < nx; ++i)
	{
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);

	return 0;
}