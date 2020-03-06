#include <stdio.h>

int GetData();
int GetMax(int a, int b, int c);
void PrintData(int a, int b, int c, int d);

int main(void)
{
	int aList[3] = { 0 };
	int nMax = -9999, i = 0;

	for (i = 0; i < 3; ++i)
	{
		aList[i] = GetData();
	}

	nMax = GetMax(aList[0], aList[1], aList[2]);

	PrintData(aList[0], aList[1], aList[2], nMax);
	return 0;
}


int GetData()
{
	int n = 0;

	printf("������ �Է��ϼ��� : \n");
	scanf_s("%d", &n);

	return n;
}


int GetMax(int a, int b, int c)
{
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;

	return max;
}

void PrintData(int a, int b, int c, int d)
{
	printf("%d, %d, %d�� ���� ū ���� %d �Դϴ�\n", a, b, c, d);
}