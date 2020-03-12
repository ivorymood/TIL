/* �� ���� */
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- �ܼ� ���� ���� �Լ� ---*/
void insertion(int a[], int n)
{
	int i, j;
	for (i = 1; i < n; i++) 
	{
		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; j--)
		{
			a[j] = a[j - 1];
		}
		a[j] = tmp;
	}
}

/*--- �� ���� �Լ� ---*/
void quick(int a[], int left, int right)
{
	// ��� ������ 9�� �����̸� �ܼ� ���� ����
	if (right - left < 9)
	{
		insertion((a + left), right - left + 1);
	}
	else
	{
		int pl = left;				/* ���� Ŀ�� */
		int pr = right;				/* ������ Ŀ�� */
		int x = a[(pl + pr) / 2];	/* �ǹ��� ��� ��Ҹ� �����մϴ�. */

		do {
			while (a[pl] < x) pl++;
			while (a[pr] > x) pr--;

			if (pl <= pr)
			{
				swap(int, a[pl], a[pr]);
				pl++;
				pr--;
			}
		} while (pl <= pr);

		if (pr - left < right - pl)
		{
			swap(int, pl, left);
			swap(int, pr, right);
		}
		if (left < pr)  quick(a, left, pr);
		if (pl < right) quick(a, pl, right);
	}
}

int main(void)
{
	int i, nx;
	int* x;			/* �迭�� ù ��° ��ҿ� ���� ������ */
	puts("�� ����");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	quick(x, 0, nx - 1);	/* �迭 x�� ���ؼ� �� �����մϴ�. */

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++)
	{
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);			/* �迭�� ���� */

	return 0;
}