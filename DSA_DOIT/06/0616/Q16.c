/* 퀵 정렬 */
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- 단순 삽입 정렬 함수 ---*/
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

/*--- 퀵 정렬 함수 ---*/
void quick(int a[], int left, int right)
{
	// 요소 개수가 9개 이하이면 단순 삽입 정렬
	if (right - left < 9)
	{
		insertion((a + left), right - left + 1);
	}
	else
	{
		int pl = left;				/* 왼쪽 커서 */
		int pr = right;				/* 오른쪽 커서 */
		int x = a[(pl + pr) / 2];	/* 피벗은 가운데 요소를 선택합니다. */

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
	int* x;			/* 배열의 첫 번째 요소에 대한 포인터 */
	puts("퀵 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	quick(x, 0, nx - 1);	/* 배열 x에 대해서 퀵 정렬합니다. */

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
	{
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);			/* 배열을 해제 */

	return 0;
}