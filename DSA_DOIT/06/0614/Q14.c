// ��� �ҽ��� �״�� ������

/* �� ���� (����� ����) */
#include <stdio.h> 
#include <stdlib.h> 
#include "IntStack.h"

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

/*--- �� ���� (����� ����) ---*/
void quick(int a[], int left, int right)
{
	IntStack lstack; /* ������ �Ǿ� ����� �ε��� ���� */
	IntStack rstack; /* ������ �ǵ� ����� �ε��� ���� */

	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	printf("a[%d] ~ a[%d]�� ���ÿ� Ǫ���մϴ�.\n", left, right);
	printf("Lstack:");   Print(&lstack);
	printf("Rstack:");   Print(&rstack);


	while (!IsEmpty(&lstack)) {
		int pl = (Pop(&lstack, &left), left);		/* ���� Ŀ�� */
		int pr = (Pop(&rstack, &right), right);		/* ������ Ŀ�� */
		int x = a[(left + right) / 2];				/* �� ��� ��� */

		printf("====================================================\n");
		printf("���ÿ��� ���� �迭�� ������ a[%d] ~ a[%d]�Դϴ�.\n", left, right);
		printf("====================================================\n");

		do {
			while (a[pl] < x) pl++;
			while (a[pr] > x) pr--;
			if (pl <= pr) {
				swap(int, a[pl], a[pr]);
				pl++;
				pr--;
			}
		} while (pl <= pr);

		if (left < pr) {
			Push(&lstack, left);	/* ���� �׷��� ���� */
			Push(&rstack, pr);		/* �ε����� Ǫ�� */

			printf("a[%d] ~ a[%d]�� ���ÿ� Ǫ���մϴ�.\n", left, pr);
			printf("Lstack:");   Print(&lstack);
			printf("Rstack:");   Print(&rstack);
		}

		if (pl < right) {
			Push(&lstack, pl);		/* ������ �׷��� ���� */
			Push(&rstack, right);	/* �ε����� Ǫ�� */

			printf("a[%d] ~ a[%d]�� ���ÿ� Ǫ���մϴ�.\n", pl, right);
			printf("Lstack:");   Print(&lstack);
			printf("Rstack:");   Print(&rstack);
		}
	}
	Terminate(&lstack);
	Terminate(&rstack);
}

int main(void)
{
	int i, nx;
	int* x; /* �迭�� ù ��° ��ҿ� ���� ������ */

	puts("�� ����");
	printf("��ڼ� :");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] :", i);
		scanf_s("%d", &x[i]);
	}

	quick(x, 0, nx - 1);			/* �迭 x�� �� ���� */

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);						/* �迭�� ���� */

	return 0;
}