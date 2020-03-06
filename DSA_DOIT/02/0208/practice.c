#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void ary_copy(int a[], const int b[], int n);
void ary_rcopy(int a[], const int b[], int n);
void shuffle(int a[], int n);
void ary_print(const int a[], int size);

int main(void)
{
	int origin[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	int copied[8] = {0};
	int copied_size = sizeof(copied) / sizeof(int);

	ary_copy(copied, origin, copied_size);
	ary_print(copied, copied_size);

	ary_rcopy(copied, origin, copied_size);
	ary_print(copied, copied_size);

	shuffle(copied, sizeof(copied) / sizeof(int));
	ary_print(copied, copied_size);

	return 0;
}

void ary_print(const int a[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d\t", a[i]);
	}
	putchar('\n');
}

void ary_copy(int a[], const int b[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		a[i] = b[i];
	}
}

void ary_rcopy(int a[], const int b[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		a[i] = b[n - i - 1];
	}
}

void shuffle(int a[], int n)
{
	int rand_idx = 0;
	int* ary_mv_idx = NULL;
	ary_mv_idx = (int*)calloc(n, sizeof(int));

	srand(time(NULL));

	for (int i = 0; i < n; ++i)
	{
		if (i > 0 && ary_mv_idx[0] == i)
		{
			continue;
		}

		while (ary_mv_idx[i] == 0)
		{
			rand_idx = rand() % n;
			printf("%d\n", rand_idx);

			if (ary_mv_idx[0] == rand_idx)
			{
				continue;
			}

			if (ary_mv_idx[rand_idx] == 0) 
			{
				ary_mv_idx[i] = rand_idx;
				ary_mv_idx[rand_idx] = i;
				printf("%d: %d  ,  %d: %d\n", i, ary_mv_idx[i], rand_idx, ary_mv_idx[rand_idx]);
			}
		}
	}

	printf("¼ÅÇÃ Ãâ·Â\n");
	ary_print(ary_mv_idx, n);

	for (int i = 0; i < n; ++i)
	{
		int pair_1 = ary_mv_idx[i];
		int pair_2 = ary_mv_idx[pair_1];
 
		int temp = a[pair_1];
		a[pair_1] = a[pair_2];
		a[pair_2] = temp;
	}

	free(ary_mv_idx);
}