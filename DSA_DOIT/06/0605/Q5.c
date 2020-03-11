#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) \
	do {type t = x; x = y; y = t;} while(0)

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
	int k = 0;
	int swaped = 0;
	int check_count = 0;
	int swap_count = 0;

	while(k < n - 1)
	{
		int last = n - 1;
		printf("�н� %d : \n", k + 1);

		for (int j = n - 1; j > k; --j)
		{
			check_count++;
			swaped = (a[j - 1] > a[j]) ? 1 : 0;
			print_array(a, n, j - 1, swaped);

			if (swaped)
			{
				swap(int, a[j - 1], a[j]);
				swap_count++;
				last = j;
			}
		}
		k = last;
	}
	printf("�񱳸� %d ȸ �߽��ϴ�. \n", check_count);
	printf("��ȯ�� %d ȸ �߽��ϴ�. \n", swap_count);
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