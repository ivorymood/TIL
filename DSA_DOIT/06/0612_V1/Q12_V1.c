/* �� ���� */
#include <stdio.h>
#include <stdlib.h>

/*--- �� ���� �Լ� ---*/
int shell(int a[], int n)
{
	int j, count = 0;
	for (int h = n / 2; h > 0; h /= 2)
	{
		for (int i = h; i < n; i++) 
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
	for (i = 0; i < nx; i++) 
	{
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