// 답안 많이 참고함

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*--- 문자열 배열(n1 × n2의 2차원 배열)을 오름차순으로 정렬 ---*/
void sort_2dstr(char* p, int nmemb, int size)
{
	qsort(p, nmemb, size, (int(*)(const void *, const void *))strcmp);
}

/*--- x, y가 가리키는 문자열 비교 함수 ---*/
int pstrcmp(const void* x, const void* y)
{
	return strcmp(*(const char**)x, *(const char**)y);
}

/*--- 문자열을 가리키는 p를 오름차순으로 정렬 ---*/
void sort_pvstr(char *p[], int nmemb)
{
	qsort(p, nmemb, sizeof(char *), pstrcmp);
}

int main(void)
{
	char a[][7] = { "LISP", "C", "Ada", "Pascal" };
	char *p[] = { "LISP", "C", "Ada", "Pascal" };

	sort_2dstr(&a[0][0], sizeof(a) / sizeof(a[0]), sizeof(a[0]));

	sort_pvstr(p, sizeof(p) / sizeof(p[0]));

	puts("오름차순으로 정렬 후");

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		printf("a[%d] = %s\n", i, a[i]);
	}
	for (int i = 0; i < sizeof(p) / sizeof(p[0]); ++i)
	{
		printf("p[%d] = %s\n", i, p[i]);
	}

	return 0;
}