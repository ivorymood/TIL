#include <stdio.h>
#include <stdlib.h>

__inline void print_intro(int a[], int n)
{
	printf("   |");
	for (int i = 0; i < n; ++i)
	{
		printf("%3d", i);
	}
	printf("\n---+");
	for (int i = 0; i < n; ++i)
	{
		printf("---");
	}
	putchar('\n');
}

__inline void print_scanning(int a[], int n, int now_idx)
{
	printf("   |");
	for (int i = 0; i < n; ++i)
	{
		char temp = (i == now_idx) ? '*' : ' ';
		printf("%3c" , temp);
	}
	printf("\n  %d|", now_idx);
	for (int i = 0; i < n; ++i)
	{
		printf("%3d", a[i]);
	}
	putchar('\n');
}

int search(int a[], int n, int key)
{
	int i;
	a[n] = key;

	print_intro(a, n);

	for (i = 0; i <= n; ++i)
	{
		print_scanning(a, n, i);
		if (a[i] == key)
		{
			break;
		}
	}

	return i == n ? -1 : i;
}

int main(void)
{
	int nx, ky, idx;
	int* x;

	puts("선형 검색(보초법)\n");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);

	x = calloc(nx + 1, sizeof(int));

	for (int i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	printf("검색값 : ");
	scanf_s("%d", &ky);

	idx = search(x, nx, ky);

	if (idx == -1)
	{
		puts("검색에 실패했습니다.");
	}
	else
	{
		printf("%d(은)는 x[%d]에 있습니다. \n", ky, idx);
	}
	free(x);

	return 0;
}