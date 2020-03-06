#include <stdio.h>
void triangleLB(int n);
void triangleLU(int n);
void triangleRU(int n);
void triangleRB(int n);
void spira(int n);
void nrpira(int n);


int main(void)
{
	int n = 0;

	do 
	{
		printf("0보다 큰 수 입력");
		scanf_s("%d", &n);
	} while (n <= 0);

	triangleLB(n);
	triangleLU(n);
	triangleRU(n);
	triangleRB(n);
	spira(n);
	nrpira(n);

	return 0;
}

void triangleLB(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%c", '*');
		}
		printf("\n");
	}
}

void triangleLU(int n)
{
	for (int i = n; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			printf("%c", '*');
		}
		printf("\n");
	}
}

void triangleRU(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf(" ");
		}
		for (int j = n; j > i; j--)
		{
			printf("%c", '*');
		}
		printf("\n");
	}
}

void triangleRB(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i + j > n)
			{
				printf("%c", '*');
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void spira(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			printf(" ");
		}
		for (int j = 0; j < (i - 1) * 2 + 1; j++)
		{
			printf("%c", '*');
		}
		printf("\n");
	}
}

void nrpira(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			printf(" ");
		}
		for (int j = 1; j <= (n - i) * 2 + 1; j++)
		{
			printf("%d", i % 10);
		}
		printf("\n");
	}
}