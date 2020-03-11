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

void bubble(int a[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		if (is_sorted(a, n))
		{
			break;
		}
		for (int j = n - 1; j > i; --j)
		{
			if (a[j - 1] > a[j])
			{
				swap(int, a[j - 1], a[j]);
			}
		}
	}
}

int main(void)
{
	int nx;
	int* x;
	puts("���� ����");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (int i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	bubble(x, nx);

	puts("������������ �����߽��ϴ�. ");
	for (int i = 0; i < nx; ++i)
	{
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);

	return 0;
}