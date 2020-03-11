#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[], int n, int key)
{
	int pl = 0; 				/* �˻� ���� �� ���� �ε��� */
	int pr = n - 1; 			/* �˻� ���� �� ���� �ε��� */
	int pc; 					/* �˻� ���� �Ѱ���� �ε��� */

	while(1) 
	{
		pc = (pl + pr) / 2;

		if (a[pc] == key) 		/* �˻� ���� */
		{
			return pc;
		}
		else if (a[pc] < key)
		{
			pl = pc + 1;
			if (pl > pr) return pl;
		}
		else
		{
			pr = pc - 1;
			if (pl > pr) return pr;
		}
	}
}

void insertion(int a[], int n)
{
	int obj;
	for (int i = 1; i < n; ++i)
	{
		int tmp = a[i];
		if ((obj = bin_search(a, i, a[i])) < 0)
		{
			obj = 0;
		}
		for (int j = i; j > obj; --j)
		{
			a[j] = a[j - 1];
		}
		a[obj] = tmp;
	}
}

int main(void)
{
	int nx;
	int* x;
	puts("���� ���� ����");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (int i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	insertion(x, nx);

	puts("������������ �����߽��ϴ�. ");
	for (int i = 0; i < nx; ++i)
	{
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);

	return 0;
}