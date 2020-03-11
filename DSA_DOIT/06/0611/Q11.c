#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bin_search_def(const int a[], int n, int key)
{
	int pl = 0; 				/* 검색 범위 맨 앞의 인덱스 */
	int pr = n - 1; 			/* 검색 범위 맨 끝의 인덱스 */
	int pc; 					/* 검색 범위 한가운데의 인덱스 */

	while (1)
	{
		pc = (pl + pr) / 2;

		if (a[pc] == key) 		/* 검색 성공 */
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
		if ((obj = bin_search_def(a, i, a[i])) < 0)
		{
			obj = 0;
		}
		memmove_s(&a[obj + 1], n * sizeof(int), &a[obj], (i - obj) * sizeof(int));
		a[obj] = tmp;
	}
}

int main(void)
{
	int nx;
	int* x;
	puts("이진 삽입 정렬 (보완)");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (int i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	insertion(x, nx);

	puts("오름차순으로 정렬했습니다. ");
	for (int i = 0; i < nx; ++i)
	{
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);

	return 0;
}