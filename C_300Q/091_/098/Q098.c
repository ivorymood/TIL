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
			puts("�޸𸮸� �Ҵ��� �� �����ϴ�");
		}
		else
		{
			puts("�޸𸮸� 1MB �Ҵ��Ͽ����ϴ� ");

			free(pmem);

			puts("�޸𸮸� �����Ͽ����ϴ�. ");
		}
	}
}