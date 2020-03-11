/* �� ���� (���� 2 : h = ��, 13, 4, 1) */
#include <stdio.h>
#include <stdlib.h>

/*--- �� ���� �Լ� (���� 2 : h = ��, 13, 4, 1) ---*/
int shell(int a[], int n)
{
	int i, j, h, count = 0;
	for (h = 1; h < n / 9; h = h * 3 + 1)
		;

	for (; h > 0; h /= 3)
	{
		for (i = h; i < n; i++)
		{
			int tmp = a[i];

			for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
			{
				a[j + h] = a[j];
				count++;
			}
			a[j + h] = tmp;
			count++;
		}
	}
	return count;
}

int main(void)
{
	int i, nx, count;
	int* x;				/* �迭�� ù ��° ��ҿ� ���� ������ */

	puts("�� ����");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	count = shell(x, nx);			/* �迭 x�� �� ���� */

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++)
	{
		printf("x[%d] = %d\n", i, x[i]);
	}
	printf("�̵� Ƚ���� %d �� �Դϴ�", count);

	free(x);				/* �迭�� ���� */

	return 0;
}