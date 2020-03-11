#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) \
	do {type t = x; x = y; y = t;} while(0)

void print_array(int a[], int n, int index, int min)
{
	for (int i = 0; i < n; ++i)
	{
		char c = (i == index) ? '*' : (i == min) ? '+' : ' ';
	
		printf("%3c", c);
	}
	putchar('\n');
	for (int i = 0; i < n; ++i)
	{
		printf("%3d", a[i]);
	}
	putchar('\n');
}

void selection(int a[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int min = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		print_array(a, n, i, min);
		swap(int, a[i], a[min]);
	}
}

int main(void)
{
	int nx;
	int* x;
	puts("�ܼ� ���� ����");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (int i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	selection(x, nx);

	puts("������������ �����߽��ϴ�. ");
	for (int i = 0; i < nx; ++i)
	{
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);

	return 0;
}