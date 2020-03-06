#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) \
 do \
 { \
	type temp = x; \
	x = y; \
	y = temp; \
 } \
while(0)

void print_array(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
	putchar('\n');
}

void ary_reverse(int a[], int n)
{
	int i;
	for (i = 0; i < n / 2; i++)
	{
		print_array(a, n);
		printf("a[%d]�� a[%d]�� ��ȯ�մϴ�. \n", a[i], a[n - i - 1]);
		swap(int, a[i], a[n - i - 1]);
	}
	print_array(a, n);
	printf("���� ������ �����մϴ�. \n");

}

int main(void)
{
	int i, nx = 0;
	int* x;

	printf("��� ����: ");
	scanf_s("%d", &nx);

	x = (int *)calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++)
	{
		printf("x[%d]", i);
		scanf_s("%d", &x[i]);
	}

	ary_reverse(x, nx);
	printf("�迭�� ��Ҹ� �������� �����߽��ϴ�. \n");

	print_array(x, nx);
	free(x);

	return 0;
}