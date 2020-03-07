#include <stdio.h>
#include <stdlib.h>

int long_cmpr_d(const long* a, const long* b);
int long_cmpr_u(const long* a, const long* b);
void* seqsearch(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*));
void* binsearch(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*));
void* bsearchx(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*));
void print_result(void* p, long* ky, int idx);

int main(void)
{
	int nx;
	long ky;
	long* x = NULL;
	long* p = NULL;

	
	printf("��� ���� : ");
	scanf_s("%d", &nx);

	x = calloc(nx, sizeof(long));
	printf("������������ �Է��ϼ���.\n");

	printf("x[0] : ");
	scanf_s("%d", &x[0]);

	// �ٷ� ���� ������ ũ�� �ٽ� �Է�
	for (int i = 1; i < nx; ++i)
	{
		do {
			printf("x[%d] : ", i);
			scanf_s("%ld", &x[i]);
		} while (x[i] > x[i - 1]);
	}

	printf("�˻��� : ");
	scanf_s("%ld", &ky);

	puts("bsearch\n");
	p = bsearch(&ky, x, nx, sizeof(long), (int(*) (const void *, const void *))long_cmpr_d);
	print_result(p, &ky, (int)(p - x));
	
	puts("seqsearch\n");
	p = seqsearch(&ky, x, nx, sizeof(long), (int(*) (const void *, const void *))long_cmpr_d);
	print_result(p, &ky, (int)(p - x));

	puts("binsearch\n");
	p = binsearch(&ky, x, nx, sizeof(long), (int(*) (const void *, const void *))long_cmpr_d);
	print_result(p, &ky, (int)(p - x));
	
	puts("bsearchx\n");
	p = bsearchx(&ky, x, nx, sizeof(long), (int(*) (const void *, const void *))long_cmpr_d);
	print_result(p, &ky, (int)(p - x));

	free(x);

	return 0;
}

void print_result(void* p, long* ky, int idx)
{
	if (p == NULL)
	{
		puts("�˻��� �����߽��ϴ�.");
	}
	else
	{
		printf("%d(��)�� x[%d]�� �ֽ��ϴ�. \n", *ky, idx);
	}
}

// long���� ���ϴ� �Լ� (��������)
int long_cmpr_d(const long* a, const long* b)
{
	if (*a < *b)
	{
		return 1;
	}
	else if (*a > *b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

// long���� ���ϴ� �Լ� (��������)
int long_cmpr_u(const long* a, const long* b)
{
	if (*a < *b)
	{
		return -1;
	}
	else if (*a > * b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void* seqsearch(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void*, const void*))
{
	char* re_base = (char*)base;
	for (size_t i = 0; i < nmemb; ++i)
	{
		if (!compar((const void*)&re_base[i * size], key))
		{
			return &re_base[i * size];
		}
	}
	return NULL;
}

void* binsearch(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*))
{
	char* re_base = (char*)base;
	size_t pl = 0;
	size_t pr = nmemb - 1;
	size_t pc;
	int result;

	do {
		pc = (pl + pr) / 2;
		result = compar((const void*)&re_base[pc * size], key);

		if (!result)
		{
			return &re_base[pc * size];
		}
		else if (result < 0)
		{
			pl = pc + 1;
		}
		else
		{
			pr = pc - 1;
		}
	} while (pl <= pr);

	return NULL;
}

void* bsearchx(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*))
{
	char* re_base = (char*)base;
	size_t pl = 0;
	size_t pr = nmemb - 1;
	size_t pc;
	int result;

	do {
		pc = (pl + pr) / 2;
		result = compar((const void*)&re_base[pc * size], key);

		if (!result)
		{
			while (!compar((const void*)&re_base[(pc - 1) * size], (const void*)&re_base[pc * size]))
			{
				pc = pc - 1;
			}
			return &re_base[pc * size];
		}
		else if (result < 0)
		{
			pl = pc + 1;
		}
		else
		{
			pr = pc - 1;
		}
	} while (pl <= pr);

	return NULL;
}