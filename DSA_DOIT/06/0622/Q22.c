/* 힙 정렬 프로그램 */
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
			if (2 * k + i    < n) printf("／");
			if (2 * k + i + 1< n) printf("＼");
			printf("%*s", pow2(height - level + 1) - 4, "");
		}
		putchar('\n');
		w *= 2;
	}

Exit:
	putchar('\n');
	putchar('\n');
}

/*--- a[left] ~ a[right]를 힙으로 만드는 함수 ---*/
static void downheap(int a[], int left, int right)
{
	int temp = a[left];					/* 뿌리 */
	int child;
	int parent;

	for (parent = left; parent < (right + 1) / 2; parent = child) 
	{
		int cl = parent * 2 + 1;		/* 왼쪽 자식 */
		int cr = cl + 1;				/* 오른쪽 자식 */
		child = (cr <= right && a[cr] > a[cl]) ? cr : cl;	/* 큰 값을 선택합니다. */

		if (temp >= a[child])
			break;

		a[parent] = a[child];
	}

	a[parent] = temp;
}

/*--- 힙 정렬 함수 ---*/
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
	int* x;			/* 배열의 첫 번째 요소에 대한 포인터 */

	puts("힙 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (int i = 0; i < nx; i++) 
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	heapsort(x, nx);		/* 배열 x를 힙 정렬 */

	puts("오름차순으로 정렬했습니다.");
	for (int i = 0; i < nx; i++)
	{
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);			/* 배열을 해제 */

	return 0;
}