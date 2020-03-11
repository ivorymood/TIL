#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) \
	do {type t = x; x = y; y = t;} while(0)

int is_sorted(const int a[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		if (a[i] > a[i + 1])
		{
			return 0;
		}
	}
	return 1;
}

void print_array(int a[], int n, int index, int swaped)
{
	for (int i = 0; i < n; ++i)
	{
		if (index == i)
		{
			printf("%-2d%2c ", a[i], ((swaped) ? '+' : '-'));
		}
		else
		{
			printf("%-5d", a[i]);
		}
	}
	putchar('\n');
}

void bubble(int a[], int n)
{
	int swaped = 0;
	int check_count = 0;
	int swap_count = 0;

	for (int i = 0; i < n - 1; ++i)
	{
		printf("패스 %d : \n", i + 1);
		if (is_sorted(a, n))
		{
			puts("정렬 완료됨");
			break;
		}
		for (int j = n - 1; j > i; --j)
		{
			check_count++;
			swaped = (a[j - 1] > a[j]) ? 1 : 0;
			print_array(a, n, j - 1, swaped);

			if (swaped)
			{
				swap(int, a[j - 1], a[j]);
				swap_count++;
			}
		}
	}
	printf("비교를 %d 회 했습니다. \n", check_count);
	printf("교환을 %d 회 했습니다. \n", swap_count);
}

int main(void)
{
	int nx;
	int* x;
	puts("버블 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (int i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	bubble(x, nx);

	puts("오름차순으로 정렬했습니다. ");
	for (int i = 0; i < nx; ++i)
	{
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);

	return 0;
}