// ��� ���� ������

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*--- ���ڿ� �迭(n1 �� n2�� 2���� �迭)�� ������������ ���� ---*/
void sort_2dstr(char* p, int nmemb, int size)
{
	qsort(p, nmemb, size, (int(*)(const void *, const void *))strcmp);
}

/*--- x, y�� ����Ű�� ���ڿ� �� �Լ� ---*/
int pstrcmp(const void* x, const void* y)
{
	return strcmp(*(const char**)x, *(const char**)y);
}

/*--- ���ڿ��� ����Ű�� p�� ������������ ���� ---*/
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

	puts("������������ ���� ��");

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