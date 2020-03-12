// 답안 그대로 가져옴
/* Q23 도수 정렬(정렬 과정 출력) */
#include <stdio.h>
#include <stdlib.h>

/*--- 도수 정렬 (배열 요소 값 제한: 0 ~ max) ---*/
void fsort(int a[], int n, int max)
{
	int i;
	int* f = calloc(max + 1, sizeof(int));		/* 누적 도수 */
	int* b = calloc(n, sizeof(int));			/* 작업용 목적 배열 */

	puts("\n정렬 전의 배열");
	for (i = 0; i < n; i++) printf("%3d", i);		putchar('\n');
	for (i = 0; i < n; i++) printf("---");			putchar('\n');
	for (i = 0; i < n; i++) printf("%3d", a[i]);	putchar('\n');

	/* [Step0] */
	for (i = 0; i <= max; i++) f[i] = 0;	
	/* [Step1] */
	for (i = 0; i < n; i++) f[a[i]]++;

	puts("\n도수 분포");
	for (i = 0; i <= max; i++) printf("%3d", i);	putchar('\n');
	for (i = 0; i <= max; i++) printf("---");		putchar('\n');
	for (i = 0; i <= max; i++) printf("%3d", f[i]);	putchar('\n');

	/* [Step2] */
	for (i = 1; i <= max; i++) f[i] += f[i - 1];	

	puts("\n누적 도수 분포");
	for (i = 0; i <= max; i++) printf("%3d", i);	putchar('\n');
	for (i = 0; i <= max; i++) printf("---");		putchar('\n');
	for (i = 0; i <= max; i++) printf("%3d", f[i]);	putchar('\n');

	putchar('\n');

	/* [Step3] */
	for (i = n - 1; i >= 0; i--) {			
		b[--f[a[i]]] = a[i];
		printf("a[%2d]의 %2d를 b[%2d]에 저장.\n", i, a[i], f[a[i]]);
	}

	/* [Step4] */
	for (i = 0; i < n; i++) a[i] = b[i];	

	puts("\n정렬 후의 배열");
	for (i = 0; i < n; i++) printf("%3d", i);		putchar('\n');
	for (i = 0; i < n; i++) printf("---");			putchar('\n');
	for (i = 0; i < n; i++) printf("%3d", a[i]);	putchar('\n');
	free(b);
	free(f);
}

int main(void)
{
	int nx;
	int* x;
	const int max = 10;

	puts("도수 정렬");
	printf("요솟수 : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	printf("0 ~ %d의 정수를 입력하세요.\n", max);
	for (int i = 0; i < nx; i++) 
	{
		do {
			printf("x[%d] : ", i);
			scanf_s("%d", &x[i]);
		} while (x[i] < 0 || x[i] > max);
	}

	fsort(x, nx, max);

	puts("오름차순으로 정렬했습니다.");
	for (int i = 0; i < nx; i++)
	{
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);

	return 0;
}
