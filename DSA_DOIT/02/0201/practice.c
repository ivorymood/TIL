#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int minof(const int a[], int n);
int sumof(const int a[], int n);
double aveof(const int a[], int n);

int main(void)
{
	int i, number;
	int* height;

	srand(time(NULL));

	do
	{
		number = rand() % 10;

	} while (number < 5 && number > 20);

	printf("��� �� : %d\n", number);

	height = (int*)calloc(number, sizeof(int));

	printf("%d ����� Ű�� �Է��ϼ���. \n", number);

	for (i = 0; i < number; i++)
	{
		height[i] = rand() % 100 + 100;
		printf("height[%d] : %d\n", i, height[i]);

	}

	printf("�ּڰ��� %d �Դϴ�. \n", minof(height, number));
	printf("�������� %d �Դϴ�. \n", sumof(height, number));
	printf("��հ��� %f �Դϴ�. \n", aveof(height, number));
	free(height);

	return 0;
}

int minof(const int a[], int n)
{
	int min = a[0];

	for (int i = 1; i < n; ++i)
	{
		if (min > a[i]) min = a[i];
	}
	return min;
}

int sumof(const int a[], int n)
{
	int sum = 0;

	for (int i = 0; i < n; ++i)
	{
		sum += a[i];
	}
	return sum;
}

double aveof(const int a[], int n)
{
	double sum = (double)sumof(a, n);

	return sum / n;
}