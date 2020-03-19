#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MEGA 1024 * 1024

void main(void)
{
	char* pmem;

	for (int i = 0; i < 10; i++)
	{
		pmem = (char*)malloc(MEGA);
	
		if (pmem == NULL)
		{
			puts("메모리를 할당할 수 없습니다");
		}
		else
		{
			puts("메모리를 1MB 할당하였습니다 ");

			free(pmem);

			puts("메모리를 해제하였습니다. ");
		}
	}
}