#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* buff;

void __mergesort(char *a, size_t left, size_t right, size_t size, int(*compar)(const void*, const void*))
{
	if (left < right)
	{
		size_t center = (left + right) / 2;
		size_t i_Center = 0;
		size_t r_count;
		size_t l_count = 0;
		size_t obj_count = left;

		__mergesort(a, left, center, size, compar);
		__mergesort(a, center + 1, right, size, compar);

		// a배열의 절반을 buff배열로 옮김
		for (r_count = left; r_count <= center; ++r_count)
		{
			memcpy_s(&buff[i_Center++ * size], size, &a[r_count * size], size);
		}

		while (r_count <= right && l_count < i_Center)
		{
			char* tmp = 
				( compar( (const void*)&buff[l_count * size], (const void*)&a[r_count * size] ) <= 0 )
				? &buff[l_count++ * size] 
				: &a[r_count++ * size];

			memcpy_s(&a[obj_count++ * size], size, (const void*)tmp, size);
		}

		while (l_count < i_Center)
		{
			memcpy_s(&a[obj_count++ * size], size, &buff[l_count++ * size], size);
		}
	}
}

void m_sort(void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *))
{
	if (nmemb <= 0) 
	{
		return ;
	}

	buff = calloc(nmemb, size);

	__mergesort(base, 0, nmemb - 1, size, compar);

	free(buff);
}

int int_cmp(const int* a, const int* b)
{
	return *a < *b ? -1 : *a > * b ? 1 : 0;
}

int main(void)
{
	int nx;
	int* x;

	puts("m_sort 함수로 정렬합니다.");
	printf("요솟수：");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (int i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	m_sort(x
		, nx
		, sizeof(int)
		, (int(*) (const void *, const void *)) int_cmp
	);

	puts("오름차순으로 정렬했습니다.");
	for (int i = 0; i < nx; ++i)
	{
		printf("x[%d] = %d\n", i, x[i]);
	}
	free(x);

	return 0;
}