#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#define MEMORY "MEMORY"

void main(void)
{
	char* pmem;

	pmem = (char*)malloc(100);

	if (pmem == NULL)
	{
		puts("�޸𸮸� �Ҵ��� �� �����ϴ�");
	}
	else
	{
		strcpy_s(pmem, 100, MEMORY);
		puts(pmem);

		free(pmem);
	}
}