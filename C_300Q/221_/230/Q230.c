#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main(void)
{
	char* pbuf;

	pbuf = malloc(100 * 1000);
	
	if (pbuf)
	{
		memset(pbuf, 0, 100 * 1000);
		strcpy_s(pbuf, 100 * 1000, "����� ��õ�� ��");
		puts(pbuf);
		free(pbuf);
	}

	return 0;
}