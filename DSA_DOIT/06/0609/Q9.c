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
	puts("�ܼ� ���� ���� (���ʹ�)");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = calloc(nx + 1, sizeof(int));

	for (int i = 1; i < nx + 1; ++i)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	insertion(x, nx);

	puts("������������ �����߽��ϴ�. ");
	for (int i = 1; i < nx + 1; ++i)
	{
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);

	return 0;
}