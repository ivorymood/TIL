#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) \
	do{type tmp = x; x = y; y = tmp;} while(0)

void quick_sort(int a[], int right)
{
	int pl = 0;
	int pr = right;
	int x = a[(pl + pr) / 2];

	do
	{
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;

		if (pl <= pr)
		{
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}

	} while (pl <= pr);
	if (0 < pr) quick_sort(a, pr);
	if (pl < right) quick_sort((a + pl), right - pl);
}

int main(void)
{
	int nx;
	int* x;

	puts("퀵 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (int i = 0; i < nx; i++) 
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	quick_sort(x, nx - 1);

	puts("오름차순으로 정렬했습니다.");
	for (int i = 0; i < nx; i++)
	{
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);			

	return 0;
}