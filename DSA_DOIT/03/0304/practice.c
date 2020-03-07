#include <stdio.h>
#include <stdlib.h>

int binary_search(int a[], int n, int key);
int bin_search2(const int a[], int n, int key);
void print_scanning(int a[], int size, int pl, int pr);
void print_intro(int a[], int n);

int main(void)
{
	int nx, ky, idx;
	int* x;

	puts("���� �˻�\n");
	printf("��� ���� : ");
	scanf_s("%d", &nx);

	x = calloc(nx, sizeof(int));

	printf("������������ �Է� \n");

	printf("x[0] : ");
	scanf_s("%d", &x[0]);

	// �ٷ� ���� ������ ������ �ٽ� �Է�
	for (int i = 1; i < nx; ++i)
	{
		do {
			printf("x[%d] : ", i);
			scanf_s("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}

	printf("�˻��� : ");
	scanf_s("%d", &ky);

	// ���� �˻�
	//idx = binary_search(x, nx, ky);
	idx = bin_search2(x, nx, ky);

	if (idx == -1)
	{
		puts("�˻��� �����߽��ϴ�.");
	}
	else
	{
		printf("%d(��)�� x[%d]�� �ֽ��ϴ�. \n", ky, idx);
	}
	free(x);

	return 0;
}

int binary_search(int a[], int n, int key)
{
	int pl = 0;
	int pr = n - 1;
	int pc;

	print_intro(a, n);

	do {

		pc = (pl + pr) / 2;
		print_scanning(a, n, pl, pr);

		if (a[pc] == key)
		{
			return pc;
		}
		else if (a[pc] < key)
		{
			pl = pc + 1;
		}
		else
		{
			pr = pc - 1;
		}

	} while (pl <= pr);


	return -1;
}

int bin_search2(const int a[], int n, int key)
{
	// �Ǿ��� ��Ҹ� ã�� binary search �����
	int pl = 0;
	int pr = n - 1;
	int pc;

	print_intro(a, n);

	do
	{
		pc = (pl + pr) / 2;
		print_scanning(a, n, pl, pr);

		if (a[pc] == key)
		{
			while (a[pc - 1] == a [pc])
			{
				pc = pc - 1;
			}
			return pc;
		}
		else if (a[pc] < key)
		{
			pl = pc + 1;
		}
		else
		{
			pr = pc - 1;
		}
	} while (pl <= pr);

	return -1;
}


__inline void print_intro(int a[], int n)
{
	printf("   |");
	for (int i = 0; i < n; ++i)
	{
		printf("%3d", i);
	}
	printf("\n---+");
	for (int i = 0; i < n; ++i)
	{
		printf("---");
	}
	putchar('\n');
}

__inline void print_scanning(int a[], int size, int pl, int pr)
{
	int pc = (pl + pr) / 2;

	printf("   |");
	for (int i = 0; i < size; ++i)
	{
		if (i == pl || i == pr || i == pc)
		{
			if (i == pc)
			{
				if (pl == pc && pc == pr)
				{
					printf("<-+->");
				}
				else if (pl == pc)
				{
					printf("<-+");

				}
				else if (pr == pc)
				{
					printf("+->");
				}
				else
				{
					printf("%3c", '+');
				}
			}
			else if (i == pl)
			{
				printf("%3s", "<-");
			}
			else if (i == pr)
			{
				printf("%3s", "->");
			}
		}
		else
		{
			printf("   ");
		}
	}
	printf("\n  %d|", pc);
	for (int i = 0; i < size; ++i)
	{
		printf("%3d", a[i]);
	}
	putchar('\n');
}
