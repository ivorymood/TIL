#include <stdio.h>
#include <stdlib.h>

int search_idx(const int a[], int n, int key, int idx[]);

int main(void)
{
	int* ary = NULL;
	int* ary_idx = NULL;
	int size = 0, key = 0, f_cnt = 0;
	

	printf("요소 개수 입력 : ");
	scanf_s("%d", &size);
	
	ary = (int*)calloc(size, sizeof(int));
	ary_idx = (int*)calloc(size, sizeof(int));

	for (int i = 0; i < size; ++i)
	{
		printf("ary[%d] 입력: ",i);
		scanf_s("%d", &ary[i]);
	}

	printf("찾고자 하는 값 입력 : ");
	scanf_s("%d", &key);

	f_cnt = search_idx(ary, size, key, ary_idx);

	printf("찾은 개수 : %d\n", f_cnt);
	for (int i = 0; i < f_cnt; ++i)
	{
		printf("%d\t", ary_idx[i]);
	}

	free(ary);
	free(ary_idx);

	return 0;
}

int search_idx(const int a[], int n, int key, int idx[])
{
	int cnt = 0;

	for (int i = 0; i < n; ++i)
	{
		if (a[i] == key)
		{
			idx[cnt++] = i;
		}
	}

	return cnt;
}