/* 셸 정렬 */
#include <stdio.h>
#include <stdlib.h>

/*--- 셸 정렬 함수 ---*/
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
	int* x;				/* 배열의 첫 번째 요소에 대한 포인터 */
	puts("셸 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);

	x = (int*)calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++) 
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	count = shell(x, nx);			/* 배열 x를 셸 정렬 */

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
	{
		printf("x[%d] = %d\n", i, x[i]);
	}
	printf("이동 횟수는 %d 번 입니다", count);

	free(x);				/* 배열을 해제 */

	return 0;
}