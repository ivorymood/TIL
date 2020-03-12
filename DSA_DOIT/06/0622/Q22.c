/* �� ���� ���α׷� */
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

static int pow2(int n)
{
	int k = 1;

	while (n--)
	{
		k *= 2;
	}
	return k;
}

static void disp_heap(int a[], int n)
{
	int i;
	int height = 1;

	i = n;
	while (i /= 2) 
	{
		height++;
	}

	i = 0;
	int w = 1;

	for (int level = 0; level < height; ++level)
	{
		printf("%*s", pow2(height - level) - 2, "");

		for (int k = 0; k < w; ++k)
		{
			printf("%02d", a[i++]);
			if (i >= n) 
				goto Exit;
			printf("%*s", pow2(height - level + 1) - 2, "");
		}
		putchar('\n');
	
		printf("%*s", pow2(height - level) - 3, "");
		for (int k = 0; k < w; ++k)
		{
			if (2 * k + i    < n) printf("��");
			if (2 * k + i + 1< n) printf("��");
			printf("%*s", pow2(height - level + 1) - 4, "");
		}
		putchar('\n');
		w *= 2;
	}

Exit:
	putchar('\n');
	putchar('\n');
}

/*--- a[left] ~ a[right]�� ������ ����� �Լ� ---*/
static void downheap(int a[], int left, int right)
{
	int temp = a[left];					/* �Ѹ� */
	int child;
	int parent;

	for (parent = left; parent < (right + 1) / 2; parent = child) 
	{
		int cl = parent * 2 + 1;		/* ���� �ڽ� */
		int cr = cl + 1;				/* ������ �ڽ� */
		child = (cr <= right && a[cr] > a[cl]) ? cr : cl;	/* ū ���� �����մϴ�. */

		if (temp >= a[child])
			break;

		a[parent] = a[child];
	}

	a[parent] = temp;
}

/*--- �� ���� �Լ� ---*/
void heapsort(int a[], int n)
{
	for (int i = (n - 1) / 2; i >= 0; i--)
	{
		disp_heap(a, n);
		downheap(a, i, n - 1);
	}

	for (int i = n - 1; i > 0; i--) 
	{
		disp_heap(a, n);
		swap(int, a[0], a[i]);
		downheap(a, 0, i - 1);
	}
}

int main(void)
{
	int nx;
	int* x;			/* �迭�� ù ��° ��ҿ� ���� ������ */

	puts("�� ����");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (int i = 0; i < nx; i++) 
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	heapsort(x, nx);		/* �迭 x�� �� ���� */

	puts("������������ �����߽��ϴ�.");
	for (int i = 0; i < nx; i++)
	{
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);			/* �迭�� ���� */

	return 0;
}