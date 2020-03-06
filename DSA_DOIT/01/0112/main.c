#include <stdio.h>
void multiply();
void plus();
void square();
void rectangle();

int main(void)
{
	multiply();
	plus();
	square();
	rectangle();

	return 0;
}

void multiply()
{
	printf("%3c", '|');
	for (int i = 1; i <= 9; i++)
	{
		printf("%3d", i);
	}
	printf("\n--+---------------------------\n");
	for (int i = 1; i <= 9; i++)
	{
		printf("%2d%c", i, '|');
		for (int j = 1; j <= 9; j++)
		{
			printf("%3d", i * j);
		}
		printf("\n");
	}
}

void plus()
{
	printf("%3c", '|');
	for (int i = 1; i <= 9; i++)
	{
		printf("%3d", i);
	}
	printf("\n--+---------------------------\n");
	for (int i = 1; i <= 9; i++)
	{
		printf("%2d%c", i, '|');
		for (int j = 1; j <= 9; j++)
		{
			printf("%3d", i + j);
		}
		printf("\n");
	}
}

void square()
{
	int n = 0;
	printf("�簢���� ����մϴ�. \n �Է��� �� : ");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%c", '*');
		}
		printf("\n");
	}
}

void rectangle()
{
	int height, width = 0;
	printf("���簢���� ����մϴ�. \n ");
	printf("���� : ");
	scanf_s("%d", &height);
	printf("�ʺ� : ");
	scanf_s("%d", &width);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			printf("%c", '*');
		}
		printf("\n");
	}
}