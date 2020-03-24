#include <stdio.h>
#include <stdlib.h>
#include <search.h>

int intcmp(const void* v1, const void* v2);

int main(void)
{
	int key = 5, * ptr;
	int array[10] = {150, 27, 33, 1, 5, 100, 99, 75, 81, 10};
	int array_size = sizeof(array) / sizeof(array[0]);

	qsort(array, array_size, sizeof(array[0]), intcmp);
	ptr = bsearch(&key, array, array_size, sizeof(array[0]), intcmp);

	if (ptr)
	{
		printf("%d를 찾았습니다. 정렬 후 위치 : %d번째", key,(ptr - array + 1));
	}
}

int intcmp(const void* v1, const void* v2)
{
	return (*(int*)v1 - *(int*)v2);
}